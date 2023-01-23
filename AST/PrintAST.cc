#include "PrintAST.hh"

PrintAST::PrintAST(ExprAST* Argument)
    : Argument(Argument)
{
    top = false;
}

void PrintAST::visit()
{
	std::cout << "print ";
    Argument->visit();
}

Value* PrintAST::codegen(driver &drv)
{
	if(gettop())
		return TopExpression(this, drv);

    auto CalleeF = drv.module->getOrInsertFunction(
        "printf",
        FunctionType::get(
            IntegerType::getDoubleTy(*drv.context), 
            PointerType::get(Type::getInt8Ty(*drv.context), 0), 
            true // VarArg
        )
    );

    llvm::Constant * format = drv.builder->CreateGlobalStringPtr("%f\n", "formatString");
    std::vector<Value *> ArgsV;
    ArgsV.push_back(format);
    ArgsV.push_back(Argument->codegen(drv));

    return drv.builder->CreateCall(CalleeF, ArgsV, "printfCall");
}