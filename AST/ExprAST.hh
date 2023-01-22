#ifndef EXPR_AST_HH
#define EXPR_AST_HH

#include "RootAST.hh"

/// ExprAST - Classe base per tutti i nodi espressione
class ExprAST : public RootAST {
protected:
  bool top;
public:
  virtual ~ExprAST() {};
  void toggle();
  bool gettop();
};

#endif // !EXPR_AST_HH