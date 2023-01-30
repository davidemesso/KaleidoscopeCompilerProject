#include "WhileExprAST.hh"

WhileExprAST::WhileExprAST(ExprAST* End, ExprAST* Body)
    : End(End), Body(Body)
{
    top = false;
}

void WhileExprAST::visit()
{
	std::cout << "while ";
    End->visit();
    std::cout << " in ";
    Body->visit();
}

Value* WhileExprAST::codegen(driver &drv)
{
	if(gettop())
		return TopExpression(this, drv);
    
    Value* BodyVal = Body->codegen(drv);
	if (!BodyVal)
		return nullptr;

    return BodyVal;
}