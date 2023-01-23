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

    const auto builder = drv.builder;

	Function* TheFunction = builder->GetInsertBlock()->getParent();

	BasicBlock* ForHeaderBB = BasicBlock::Create(*drv.context, "for.header");
	BasicBlock* ForBodyBB   = BasicBlock::Create(*drv.context, "for.body");
	BasicBlock* ForLatchBB  = BasicBlock::Create(*drv.context, "latch");
	BasicBlock* ExitBB      = BasicBlock::Create(*drv.context, "exit");

    Value* StartVal = Start->codegen(drv);
    if (!StartVal)
        return nullptr;

    builder->CreateBr(ForHeaderBB);
    auto InitBB = builder->GetInsertBlock();

    // Header
    TheFunction->getBasicBlockList().insert(TheFunction->end(), ForHeaderBB);
    builder->SetInsertPoint(ForHeaderBB);
    PHINode* Variable = builder->CreatePHI(
        Type::getDoubleTy(*drv.context),
        2, 
        VarName.c_str()
    );

    Value *OldVal = drv.NamedValues[VarName];
    drv.NamedValues[VarName] = Variable;

    Variable->addIncoming(StartVal, InitBB);
    Value *CondV = End->codegen(drv);
	if (!CondV)
		return nullptr;

	Value* EndCondition = builder->CreateFCmpONE(
		CondV,
		ConstantFP::get(*drv.context, APFloat(0.)),
        "forCond"
	);
    builder->CreateCondBr(EndCondition, ForBodyBB, ExitBB);
    ForHeaderBB = builder->GetInsertBlock();


    // Body
    TheFunction->getBasicBlockList().insert(TheFunction->end(), ForBodyBB);
	builder->SetInsertPoint(ForBodyBB);

    Value* BodyVal = Body->codegen(drv);
	if (!BodyVal)
		return nullptr;
    
    builder->CreateBr(ForLatchBB);
    ForBodyBB = builder->GetInsertBlock();
    
    // Latch
    TheFunction->getBasicBlockList().insert(TheFunction->end(), ForLatchBB);
	builder->SetInsertPoint(ForLatchBB);
	
    Value* StepVal = Step->codegen(drv);
	if (!StepVal)
		return nullptr;
    
    Value* NextVal = builder->CreateFAdd(Variable, StepVal, "nextVal");
    Variable->addIncoming(NextVal, ForLatchBB);

    builder->CreateBr(ForHeaderBB);
    ForLatchBB = builder->GetInsertBlock();
    
    // EXIT
    TheFunction->getBasicBlockList().insert(TheFunction->end(), ExitBB);
	builder->SetInsertPoint(ExitBB);
    
    if (OldVal)
        drv.NamedValues[VarName] = OldVal;
    else
        drv.NamedValues.erase(VarName);

    return BodyVal;
}