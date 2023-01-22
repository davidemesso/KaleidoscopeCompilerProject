#include "BinaryExprAST.hh"
#include "Utils/LogError.hh"

// Helper function
llvm::Value* comparisonToFP(const driver& drv, llvm::Value* cond) {
  return 
    drv.builder->CreateUIToFP(
      cond, 
      Type::getDoubleTy(*drv.context),
      "compresultregister"
    );
}

/******************** Binary Expression Tree **********************/
BinaryExprAST::BinaryExprAST(char Op, ExprAST* LHS, ExprAST* RHS):
  Op(Op), LHS(LHS), RHS(RHS) { top = false; };
 
void BinaryExprAST::visit() {
  std::cout << "(" << Op << " ";
  LHS->visit();
  if (RHS!=nullptr) RHS->visit();
  std::cout << ")";
};

Value *BinaryExprAST::codegen(driver& drv) {
  if (gettop()) {
    return TopExpression(this, drv);
  } else {
    Value *L = LHS->codegen(drv);
    Value *R = RHS->codegen(drv);
    if (!L || !R) return nullptr;
    switch (Op) {
    case '+':
      return drv.builder->CreateFAdd(L,R,"addregister");
    case '-':
      return drv.builder->CreateFSub(L,R,"subregister");
    case '*':
      return drv.builder->CreateFMul(L,R,"mulregister");
    case '/':
      return drv.builder->CreateFDiv(L,R,"divregister");
    case '<':
    {
      auto cond = drv.builder->CreateFCmpULT(L, R, "compregister");
      return drv.builder->CreateUIToFP(
        cond, 
        Type::getDoubleTy(*drv.context),
        "compresultregister"
      );
    }
    case '>':
    {
      auto cond = drv.builder->CreateFCmpUGT(L, R, "compregister");
      return comparisonToFP(drv, cond);
    }
    case 'g':
    {
      auto cond = drv.builder->CreateFCmpUGE(L, R, "compregister");
      return comparisonToFP(drv, cond);
    }
    case 'l':
    {
      auto cond = drv.builder->CreateFCmpULE(L, R, "compregister");
      return comparisonToFP(drv, cond);
    }
    case '=':
    {
      auto cond = drv.builder->CreateFCmpUEQ(L, R, "compregister");
      return comparisonToFP(drv, cond);
    }
    case '!':
    {
      auto cond = drv.builder->CreateFCmpUNE(L, R, "compregister");
      return comparisonToFP(drv, cond);
    }
    case ':':
      return R;
    default:  
      LogErrorV("Operatore binario non supportato");
      return nullptr;
    }
  }
};