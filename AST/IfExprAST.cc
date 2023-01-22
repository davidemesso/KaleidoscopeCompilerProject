#include "IfExprAST.hh"

IfExprAST::IfExprAST(ExprAST* Condition, ExprAST* Then, ExprAST* Else)
	: Condition(Condition), Then(Then), Else(Else)
{
	top = false;
}

void IfExprAST::visit()
{
	std::cout << "if ";
	Condition->visit();
	std::cout << " then ";
	Then->visit();
	if(Else != nullptr)
	{
		std::cout << " else ";
		Else->visit();
	}
	std::cout << " fi";
}

Value* IfExprAST::codegen(driver &drv)
{
	if(gettop())
		return TopExpression(this, drv);

	const auto builder = drv.builder;
	Value *CondV = Condition->codegen(drv);
	if (!CondV)
		return nullptr;

	Value* ifCondition = builder->CreateFCmpONE(
		CondV, 
		ConstantFP::get(*drv.context, APFloat(0.f)), 
		"ifcond"
	);

	Function *TheFunction = builder->GetInsertBlock()->getParent();

	// Create blocks for the then and else cases.  Insert the 'then' block at the
	// end of the function.
	BasicBlock *thenBB  = BasicBlock::Create(*drv.context, "then", TheFunction);
	BasicBlock *elseBB  = BasicBlock::Create(*drv.context, "else");
	BasicBlock *mergeBB = BasicBlock::Create(*drv.context, "ifcont");

	builder->CreateCondBr(ifCondition, thenBB, elseBB);

	// THEN
	builder->SetInsertPoint(thenBB);

	Value *thenValue = Then->codegen(drv);
	if (!thenValue)
		return nullptr;

	builder->CreateBr(mergeBB);
	// Codegen of 'Then' can change the current block, update ThenBB for the PHI.
	thenBB = builder->GetInsertBlock();

	// ELSE
	TheFunction->getBasicBlockList().insert(TheFunction->end(), elseBB);
	builder->SetInsertPoint(elseBB);

	Value *elseValue = Else->codegen(drv);
	if (!elseValue)
		return nullptr;

	builder->CreateBr(mergeBB);
	// codegen of 'Else' can change the current block, update ElseBB for the PHI.
	elseBB = builder->GetInsertBlock();
	
	// MERGE
	TheFunction->getBasicBlockList().insert(TheFunction->end(), mergeBB);
	builder->SetInsertPoint(mergeBB);
	PHINode* IfRes = builder->CreatePHI(
		Type::getDoubleTy(*drv.context),
		2,
		"IfRes"
	);
	IfRes->addIncoming(thenValue, thenBB);
	IfRes->addIncoming(elseValue, elseBB);

	return IfRes;
}