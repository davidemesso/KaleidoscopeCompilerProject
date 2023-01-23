%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.2"
%defines

%define api.token.constructor
%define api.location.file none
%define api.value.type variant
%define parse.assert

%code requires {
  #include <string>
  #include <exception>
  class RootAST;
  class ExprAST;
  class driver;
  class FunctionAST;
  class SeqAST;
  class PrototypeAST;
  class IfExprAST;
}

// The parsing context.
%param { driver& drv }

%locations

%define parse.trace
%define parse.error verbose

%code {
# include "driver.hh"
# include "AST/IfExprAST.hh"
# include "AST/SeqAST.hh"
# include "AST/FunctionAST.hh"
# include "AST/PrototypeAST.hh"
# include "AST/NumberExprAST.hh"
# include "AST/VariableExprAST.hh"
# include "AST/BinaryExprAST.hh"
# include "AST/UnaryExprAST.hh"
# include "AST/CallExprAST.hh"
# include "AST/ForExprAST.hh"
# include "AST/PrintAST.hh"
}

%define api.token.prefix {TOK_}
%token
  END 0 "end of file"
  SEMICOLON  ";"
  COMMA      ","
  MINUS      "-"
  PLUS       "+"
  STAR       "*"
  SLASH      "/"
  GT         ">"
  LT         "<"
  GE         ">="
  LE         "<="
  EQ         "=="
  NE         "!="
  LPAREN     "("
  RPAREN     ")"
  CONCAT     ":"
  ASSIGN     "="
  EXTERN     "extern"
  DEF        "def"
  IF         "if"
  THEN       "then"
  ELSE       "else"
  FI         "fi"
  FOR        "for"
  IN         "in"
  ENDFOR     "end"
  PRINT      "print"
;

%token <std::string> IDENTIFIER "id"
%token <double> NUMBER "number"
%type <ExprAST*> exp
%type <ExprAST*> idexp
%type <std::vector<ExprAST*>> optexp
%type <std::vector<ExprAST*>> explist
%type <ExprAST*> ifexp
%type <ExprAST*> forexp
%type <ExprAST*> step
%type <RootAST*> program
%type <RootAST*> top
%type <FunctionAST*> definition
%type <PrototypeAST*> external
%type <PrototypeAST*> proto
%type <std::vector<std::string>> idseq
%type <ExprAST*> print

%right ":"
%left "<" ">" EQ NE LE GE
%left "+" "-"
%left "*" "/"

%%
%start startsymb;


startsymb:
program                 { drv.root = $1; };

program:
  %empty                { $$ = new SeqAST(nullptr,nullptr); }
|  top ";" program      { $$ = new SeqAST($1,$3); }
;

top:
%empty                  { $$ = nullptr; }
| definition            { $$ = $1; }
| external              { $$ = $1; }
| exp                   { $$ = $1; $1->toggle(); }
;

definition:
  "def" proto exp       { $$ = new FunctionAST($2,$3); $2->noemit(); }
;

external:
  "extern" proto        { $$ = $2; }
;

proto:
  "id" "(" idseq ")"    { $$ = new PrototypeAST($1,$3); }
;

idseq:
  %empty                { std::vector<std::string> args;
                          $$ = args; }
| "id" idseq            { $2.insert($2.begin(),$1); $$ = $2; }
;

exp:
  exp "+" exp           { $$ = new BinaryExprAST('+',$1,$3); }
| exp "-" exp           { $$ = new BinaryExprAST('-',$1,$3); }
| exp "*" exp           { $$ = new BinaryExprAST('*',$1,$3); }
| exp "/" exp           { $$ = new BinaryExprAST('/',$1,$3); }
| exp LE  exp %prec LE  { $$ = new BinaryExprAST('l',$1,$3); }
| exp GE  exp %prec GE  { $$ = new BinaryExprAST('g',$1,$3); }
| exp "<" exp           { $$ = new BinaryExprAST('<',$1,$3); }
| exp ">" exp           { $$ = new BinaryExprAST('>',$1,$3); }
| exp EQ exp            { $$ = new BinaryExprAST('=',$1,$3); }
| exp NE exp            { $$ = new BinaryExprAST('!',$1,$3); }
| idexp                 { $$ = $1; }
| "(" exp ")"           { $$ = $2; }
| "number"              { $$ = new NumberExprAST($1); }
| "-" "number"          { $$ = new UnaryExprAST('-', new NumberExprAST($2)); }
| "-" "(" exp ")"       { $$ = new UnaryExprAST('-', $3); }
| exp ":" exp           { $$ = new BinaryExprAST(':', $1, $3); }
| ifexp                 { $$ = $1; }
| forexp                { $$ = $1; }
| print %prec PRINT     { $$ = $1; }
;

idexp:
  "id"                  { $$ = new VariableExprAST($1); }
| "id" "(" optexp ")"   { $$ = new CallExprAST($1,$3); }
;

optexp:
%empty                  { std::vector<ExprAST*> args;
                          args.push_back(nullptr);
			                    $$ = args; }
| explist               { $$ = $1; };

explist:
  exp                   { std::vector<ExprAST*> args;
                          args.push_back($1);
			                    $$ = args; }
| exp "," explist       { $3.insert($3.begin(), $1); $$ = $3; }
;

ifexp:
  IF exp THEN exp ELSE exp FI  { $$ = new IfExprAST($2, $4, $6);}
/* | IF exp THEN exp FI           { $$ = new IfExprAST($2, $4, nullptr); } */
;

forexp:
  FOR "id" "=" exp "," exp step IN exp ENDFOR { $$ = new ForExprAST($2, $4, $6, $7, $9); }
;

step:
  "," exp   { $$ = $2; }
| %empty    { $$ = new NumberExprAST(1.f); }
;

print:
  PRINT "(" exp ")"     { $$ = new PrintAST($3); }
%%

void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
