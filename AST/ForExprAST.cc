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

    return nullptr;
}