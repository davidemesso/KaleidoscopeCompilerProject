#include "UnaryExprAST.hh"
#include "NumberExprAST.hh"
#include "Utils/LogError.hh"

/******************** Binary Expression Tree **********************/
UnaryExprAST::UnaryExprAST(char Op, ExprAST* Expr):
  Op(Op), Expr(Expr) { top = false; };
 
void UnaryExprAST::visit() {
  std::cout << "(" << Op << " ";
  if (Expr!=nullptr) Expr->visit();
  std::cout << ")";
};

Value *UnaryExprAST::codegen(driver& drv) {
  if (gettop()) {
    return TopExpression(this, drv);
  } else {
    Value* val = Expr->codegen(drv);
    if (!val) return nullptr;
    switch (Op) {
    case '-':
    {
        NumberExprAST* minusOne = new NumberExprAST(-1.f);
        return drv.builder->CreateFMul(
            val,
            minusOne->codegen(drv), 
            "inversionRegister"
        );
    }
    default:  
      LogErrorV("Operatore binario non supportato");
      return nullptr;
    }
  }
};