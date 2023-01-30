#include "VarExprAST.hh"
#include "Utils/LogError.hh"

/****************** Variable Expression TreeAST *******************/
VarExprAST::VarExprAST(
	std::vector<std::pair<std::string, ExprAST *>> VarNames,
	ExprAST *Body
) 
	: VarNames(VarNames), Body(Body)
{
	top = false;
};

void VarExprAST::visit()
{
	std::cout << "var ";
	for (auto &Var : VarNames) 
	{
		std::cout << Var.first << " = ";
		Var.second->visit();
	}
	std::cout << " in ";
	Body->visit();
	std::cout << " end ";
};

Value *VarExprAST::codegen(driver &drv)
{
	std::vector<AllocaInst *> OldBindings;

	Function *TheFunction = drv.builder->GetInsertBlock()->getParent();

	for (auto &Var : VarNames) 
	{
		const std::string &VarName = Var.first;
		ExprAST* Init = Var.second;

		Value *InitVal = Init->codegen(drv);
		if (!InitVal)
			return nullptr;

		AllocaInst *Alloca = CreateEntryBlockAlloca(drv, TheFunction, VarName);
		drv.builder->CreateStore(InitVal, Alloca);

		// Remember the old variable binding so that we can restore the binding when
		// we unrecurse.
		OldBindings.push_back(drv.NamedValues[VarName]);

		// Remember this binding.
		drv.NamedValues[VarName] = Alloca;
	}

	// Codegen the body, now that all vars are in scope.
	Value *BodyVal = Body->codegen(drv);
	if (!BodyVal)
		return nullptr;

	// Pop all our variables from scope.
	for (unsigned i = 0, e = VarNames.size(); i != e; ++i)
		drv.NamedValues[VarNames[i].first] = OldBindings[i];

	// Return the body computation.
	return BodyVal;
};