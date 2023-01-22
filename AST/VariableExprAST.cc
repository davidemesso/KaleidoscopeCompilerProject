#include "VariableExprAST.hh"
#include "Utils/LogError.hh"

/****************** Variable Expression TreeAST *******************/
VariableExprAST::VariableExprAST(std::string &Name):
  Name(Name) { top = false; };

const std::string& VariableExprAST::getName() const {
  return Name;
};

void VariableExprAST::visit() {
  std::cout << getName() << " ";
};

Value *VariableExprAST::codegen(driver& drv) {
  if (gettop()) {
    return TopExpression(this, drv);
  } else {
    Value *V = drv.NamedValues[Name];
    if (!V) LogErrorV("Variabile non definita");
    return V;
  }
};