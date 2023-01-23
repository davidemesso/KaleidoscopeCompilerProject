#include "ForExprAST.hh"

ForExprAST::ForExprAST(        
    const std::string &VarName, 
    ExprAST* Start,
    ExprAST* End, 
    ExprAST* Step,
    ExprAST* Body
)
    : VarName(VarName), Start(Start), End(End), Step(Step), Body(Body)
{
    top = false;
}

void ForExprAST::visit()
{
	std::cout << "for " << VarName;
	std::cout << " = ";
    Start->visit();
    std::cout << " , ";
    End->visit();
    std::cout << " , ";
    Step->visit();
    std::cout << " in ";
    Body->visit();
}

Value* ForExprAST::codegen(driver &drv)
{
	if(gettop())
		return TopExpression(this, drv);

    Value *StartVal = Start->codegen(drv);
    if (!StartVal)
        return nullptr;

    const auto builder = drv.builder;

    // Make the new basic block for the loop header, inserting after current
    // block.
    Function *TheFunction = builder->GetInsertBlock()->getParent();
    BasicBlock *PreheaderBB = builder->GetInsertBlock();
    BasicBlock *LoopBB = BasicBlock::Create(*drv.context, "loop", TheFunction);

    // Insert an explicit fall through from the current block to the LoopBB.
    builder->CreateBr(LoopBB);

    // Start insertion in LoopBB.
    builder->SetInsertPoint(LoopBB);

    // Start the PHI node with an entry for Start.
    PHINode *Variable =
        builder->CreatePHI(Type::getDoubleTy(*drv.context), 2, VarName);
    Variable->addIncoming(StartVal, PreheaderBB);

    // Within the loop, the variable is defined equal to the PHI node.  If it
    // shadows an existing variable, we have to restore it, so save it now.
    Value *OldVal = drv.NamedValues[VarName];
    drv.NamedValues[VarName] = Variable;

    // Emit the body of the loop.  This, like any other expr, can change the
    // current BB.  Note that we ignore the value computed by the body, but don't
    // allow an error.
    if (!Body->codegen(drv))
        return nullptr;

    // Emit the step value.
    Value *StepVal = nullptr;
    if (Step) {
        StepVal = Step->codegen(drv);
        if (!StepVal)
        return nullptr;
    } else {
        // If not specified, use 1.0.
        StepVal = ConstantFP::get(*drv.context, APFloat(1.0));
    }

    Value *NextVar = builder->CreateFAdd(Variable, StepVal, "nextvar");

    // Compute the end condition.
    Value *EndCond = End->codegen(drv);
    if (!EndCond)
        return nullptr;

    // Convert condition to a bool by comparing non-equal to 0.0.
    EndCond = builder->CreateFCmpONE(
        EndCond, ConstantFP::get(*drv.context, APFloat(0.0)), "loopcond");

    // Create the "after loop" block and insert it.
    BasicBlock *LoopEndBB = builder->GetInsertBlock();
    BasicBlock *AfterBB =
        BasicBlock::Create(*drv.context, "afterloop", TheFunction);

    // Insert the conditional branch into the end of LoopEndBB.
    builder->CreateCondBr(EndCond, LoopBB, AfterBB);

    // Any new code will be inserted in AfterBB.
    builder->SetInsertPoint(AfterBB);

    // Add a new entry to the PHI node for the backedge.
    Variable->addIncoming(NextVar, LoopEndBB);

    // Restore the unshadowed variable.
    if (OldVal)
        drv.NamedValues[VarName] = OldVal;
    else
        drv.NamedValues.erase(VarName);

    // for expr always returns 0.0.
    return Constant::getNullValue(Type::getDoubleTy(*drv.context));
}