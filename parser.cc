// A Bison parser, made by GNU Bison 3.7.5.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hh"


// Unqualified %code blocks.
#line 28 "parser.yy"

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
# include "AST/VarExprAST.hh"
# include "AST/WhileExprAST.hh"
# include "AST/ArrayExprAST.hh"
# include "AST/ArrayAssignExprAST.hh"

#line 65 "parser.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 157 "parser.cc"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_idexp: // idexp
      case symbol_kind::S_ifexp: // ifexp
      case symbol_kind::S_forexp: // forexp
      case symbol_kind::S_step: // step
      case symbol_kind::S_whilexp: // whilexp
      case symbol_kind::S_print: // print
      case symbol_kind::S_varexp: // varexp
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_arrayexp: // arrayexp
        value.YY_MOVE_OR_COPY< ExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_definition: // definition
        value.YY_MOVE_OR_COPY< FunctionAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_external: // external
      case symbol_kind::S_proto: // proto
        value.YY_MOVE_OR_COPY< PrototypeAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_top: // top
        value.YY_MOVE_OR_COPY< RootAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.YY_MOVE_OR_COPY< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pair: // pair
      case symbol_kind::S_arraydef: // arraydef
        value.YY_MOVE_OR_COPY< std::pair<std::string,ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_optexp: // optexp
      case symbol_kind::S_explist: // explist
        value.YY_MOVE_OR_COPY< std::vector<ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_varlist: // varlist
        value.YY_MOVE_OR_COPY< std::vector<std::pair<std::string, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_idseq: // idseq
        value.YY_MOVE_OR_COPY< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_idexp: // idexp
      case symbol_kind::S_ifexp: // ifexp
      case symbol_kind::S_forexp: // forexp
      case symbol_kind::S_step: // step
      case symbol_kind::S_whilexp: // whilexp
      case symbol_kind::S_print: // print
      case symbol_kind::S_varexp: // varexp
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_arrayexp: // arrayexp
        value.move< ExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_definition: // definition
        value.move< FunctionAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_external: // external
      case symbol_kind::S_proto: // proto
        value.move< PrototypeAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_top: // top
        value.move< RootAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< double > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pair: // pair
      case symbol_kind::S_arraydef: // arraydef
        value.move< std::pair<std::string,ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_optexp: // optexp
      case symbol_kind::S_explist: // explist
        value.move< std::vector<ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_varlist: // varlist
        value.move< std::vector<std::pair<std::string, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_idseq: // idseq
        value.move< std::vector<std::string> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_idexp: // idexp
      case symbol_kind::S_ifexp: // ifexp
      case symbol_kind::S_forexp: // forexp
      case symbol_kind::S_step: // step
      case symbol_kind::S_whilexp: // whilexp
      case symbol_kind::S_print: // print
      case symbol_kind::S_varexp: // varexp
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_arrayexp: // arrayexp
        value.copy< ExprAST* > (that.value);
        break;

      case symbol_kind::S_definition: // definition
        value.copy< FunctionAST* > (that.value);
        break;

      case symbol_kind::S_external: // external
      case symbol_kind::S_proto: // proto
        value.copy< PrototypeAST* > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_top: // top
        value.copy< RootAST* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.copy< double > (that.value);
        break;

      case symbol_kind::S_pair: // pair
      case symbol_kind::S_arraydef: // arraydef
        value.copy< std::pair<std::string,ExprAST*> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_optexp: // optexp
      case symbol_kind::S_explist: // explist
        value.copy< std::vector<ExprAST*> > (that.value);
        break;

      case symbol_kind::S_varlist: // varlist
        value.copy< std::vector<std::pair<std::string, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_idseq: // idseq
        value.copy< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_idexp: // idexp
      case symbol_kind::S_ifexp: // ifexp
      case symbol_kind::S_forexp: // forexp
      case symbol_kind::S_step: // step
      case symbol_kind::S_whilexp: // whilexp
      case symbol_kind::S_print: // print
      case symbol_kind::S_varexp: // varexp
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_arrayexp: // arrayexp
        value.move< ExprAST* > (that.value);
        break;

      case symbol_kind::S_definition: // definition
        value.move< FunctionAST* > (that.value);
        break;

      case symbol_kind::S_external: // external
      case symbol_kind::S_proto: // proto
        value.move< PrototypeAST* > (that.value);
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_top: // top
        value.move< RootAST* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< double > (that.value);
        break;

      case symbol_kind::S_pair: // pair
      case symbol_kind::S_arraydef: // arraydef
        value.move< std::pair<std::string,ExprAST*> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_optexp: // optexp
      case symbol_kind::S_explist: // explist
        value.move< std::vector<ExprAST*> > (that.value);
        break;

      case symbol_kind::S_varlist: // varlist
        value.move< std::vector<std::pair<std::string, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_idseq: // idseq
        value.move< std::vector<std::string> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_exp: // exp
      case symbol_kind::S_idexp: // idexp
      case symbol_kind::S_ifexp: // ifexp
      case symbol_kind::S_forexp: // forexp
      case symbol_kind::S_step: // step
      case symbol_kind::S_whilexp: // whilexp
      case symbol_kind::S_print: // print
      case symbol_kind::S_varexp: // varexp
      case symbol_kind::S_assignment: // assignment
      case symbol_kind::S_arrayexp: // arrayexp
        yylhs.value.emplace< ExprAST* > ();
        break;

      case symbol_kind::S_definition: // definition
        yylhs.value.emplace< FunctionAST* > ();
        break;

      case symbol_kind::S_external: // external
      case symbol_kind::S_proto: // proto
        yylhs.value.emplace< PrototypeAST* > ();
        break;

      case symbol_kind::S_program: // program
      case symbol_kind::S_top: // top
        yylhs.value.emplace< RootAST* > ();
        break;

      case symbol_kind::S_NUMBER: // "number"
        yylhs.value.emplace< double > ();
        break;

      case symbol_kind::S_pair: // pair
      case symbol_kind::S_arraydef: // arraydef
        yylhs.value.emplace< std::pair<std::string,ExprAST*> > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_optexp: // optexp
      case symbol_kind::S_explist: // explist
        yylhs.value.emplace< std::vector<ExprAST*> > ();
        break;

      case symbol_kind::S_varlist: // varlist
        yylhs.value.emplace< std::vector<std::pair<std::string, ExprAST*>> > ();
        break;

      case symbol_kind::S_idseq: // idseq
        yylhs.value.emplace< std::vector<std::string> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // startsymb: program
#line 119 "parser.yy"
                        { drv.root = yystack_[0].value.as < RootAST* > (); }
#line 816 "parser.cc"
    break;

  case 3: // program: %empty
#line 122 "parser.yy"
                        { yylhs.value.as < RootAST* > () = new SeqAST(nullptr,nullptr); }
#line 822 "parser.cc"
    break;

  case 4: // program: top ";" program
#line 123 "parser.yy"
                        { yylhs.value.as < RootAST* > () = new SeqAST(yystack_[2].value.as < RootAST* > (),yystack_[0].value.as < RootAST* > ()); }
#line 828 "parser.cc"
    break;

  case 5: // top: %empty
#line 127 "parser.yy"
                        { yylhs.value.as < RootAST* > () = nullptr; }
#line 834 "parser.cc"
    break;

  case 6: // top: definition
#line 128 "parser.yy"
                        { yylhs.value.as < RootAST* > () = yystack_[0].value.as < FunctionAST* > (); }
#line 840 "parser.cc"
    break;

  case 7: // top: external
#line 129 "parser.yy"
                        { yylhs.value.as < RootAST* > () = yystack_[0].value.as < PrototypeAST* > (); }
#line 846 "parser.cc"
    break;

  case 8: // top: exp
#line 130 "parser.yy"
                        { yylhs.value.as < RootAST* > () = yystack_[0].value.as < ExprAST* > (); yystack_[0].value.as < ExprAST* > ()->toggle(); }
#line 852 "parser.cc"
    break;

  case 9: // definition: "def" proto exp
#line 134 "parser.yy"
                        { yylhs.value.as < FunctionAST* > () = new FunctionAST(yystack_[1].value.as < PrototypeAST* > (),yystack_[0].value.as < ExprAST* > ()); yystack_[1].value.as < PrototypeAST* > ()->noemit(); }
#line 858 "parser.cc"
    break;

  case 10: // external: "extern" proto
#line 138 "parser.yy"
                        { yylhs.value.as < PrototypeAST* > () = yystack_[0].value.as < PrototypeAST* > (); }
#line 864 "parser.cc"
    break;

  case 11: // proto: "id" "(" idseq ")"
#line 142 "parser.yy"
                        { yylhs.value.as < PrototypeAST* > () = new PrototypeAST(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<std::string> > ()); }
#line 870 "parser.cc"
    break;

  case 12: // idseq: %empty
#line 146 "parser.yy"
                        { std::vector<std::string> args;
                          yylhs.value.as < std::vector<std::string> > () = args; }
#line 877 "parser.cc"
    break;

  case 13: // idseq: "id" idseq
#line 148 "parser.yy"
                        { yystack_[0].value.as < std::vector<std::string> > ().insert(yystack_[0].value.as < std::vector<std::string> > ().begin(),yystack_[1].value.as < std::string > ()); yylhs.value.as < std::vector<std::string> > () = yystack_[0].value.as < std::vector<std::string> > (); }
#line 883 "parser.cc"
    break;

  case 14: // exp: exp "+" exp
#line 152 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('+',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 889 "parser.cc"
    break;

  case 15: // exp: exp "-" exp
#line 153 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('-',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 895 "parser.cc"
    break;

  case 16: // exp: exp "*" exp
#line 154 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('*',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 901 "parser.cc"
    break;

  case 17: // exp: exp "/" exp
#line 155 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('/',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 907 "parser.cc"
    break;

  case 18: // exp: exp "%" exp
#line 156 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('%',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 913 "parser.cc"
    break;

  case 19: // exp: exp "<=" exp
#line 157 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('l',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 919 "parser.cc"
    break;

  case 20: // exp: exp ">=" exp
#line 158 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('g',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 925 "parser.cc"
    break;

  case 21: // exp: exp "<" exp
#line 159 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('<',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 931 "parser.cc"
    break;

  case 22: // exp: exp ">" exp
#line 160 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('>',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 937 "parser.cc"
    break;

  case 23: // exp: exp "==" exp
#line 161 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('e',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 943 "parser.cc"
    break;

  case 24: // exp: exp "!=" exp
#line 162 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST('!',yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 949 "parser.cc"
    break;

  case 25: // exp: idexp
#line 163 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 955 "parser.cc"
    break;

  case 26: // exp: "(" exp ")"
#line 164 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[1].value.as < ExprAST* > (); }
#line 961 "parser.cc"
    break;

  case 27: // exp: "number"
#line 165 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new NumberExprAST(yystack_[0].value.as < double > ()); }
#line 967 "parser.cc"
    break;

  case 28: // exp: "-" "number"
#line 166 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new UnaryExprAST('-', new NumberExprAST(yystack_[0].value.as < double > ())); }
#line 973 "parser.cc"
    break;

  case 29: // exp: "-" "(" exp ")"
#line 167 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new UnaryExprAST('-', yystack_[1].value.as < ExprAST* > ()); }
#line 979 "parser.cc"
    break;

  case 30: // exp: "-" idexp
#line 168 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new UnaryExprAST('-', yystack_[0].value.as < ExprAST* > ()); }
#line 985 "parser.cc"
    break;

  case 31: // exp: "!" "number"
#line 169 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new UnaryExprAST('!', new NumberExprAST(yystack_[0].value.as < double > ())); }
#line 991 "parser.cc"
    break;

  case 32: // exp: "!" "(" exp ")"
#line 170 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new UnaryExprAST('!', yystack_[1].value.as < ExprAST* > ()); }
#line 997 "parser.cc"
    break;

  case 33: // exp: "!" idexp
#line 171 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new UnaryExprAST('!', yystack_[0].value.as < ExprAST* > ()); }
#line 1003 "parser.cc"
    break;

  case 34: // exp: exp ":" exp
#line 172 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new BinaryExprAST(':', yystack_[2].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ()); }
#line 1009 "parser.cc"
    break;

  case 35: // exp: ifexp
#line 173 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1015 "parser.cc"
    break;

  case 36: // exp: forexp
#line 174 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1021 "parser.cc"
    break;

  case 37: // exp: print
#line 175 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1027 "parser.cc"
    break;

  case 38: // exp: varexp
#line 176 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1033 "parser.cc"
    break;

  case 39: // exp: assignment
#line 177 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1039 "parser.cc"
    break;

  case 40: // exp: whilexp
#line 178 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1045 "parser.cc"
    break;

  case 41: // exp: arrayexp
#line 179 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1051 "parser.cc"
    break;

  case 42: // idexp: "id"
#line 183 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new VariableExprAST(yystack_[0].value.as < std::string > ()); }
#line 1057 "parser.cc"
    break;

  case 43: // idexp: "id" "(" optexp ")"
#line 184 "parser.yy"
                        { yylhs.value.as < ExprAST* > () = new CallExprAST(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<ExprAST*> > ()); }
#line 1063 "parser.cc"
    break;

  case 44: // optexp: %empty
#line 188 "parser.yy"
                        { std::vector<ExprAST*> args;
                          args.push_back(nullptr);
			                    yylhs.value.as < std::vector<ExprAST*> > () = args; }
#line 1071 "parser.cc"
    break;

  case 45: // optexp: explist
#line 191 "parser.yy"
                        { yylhs.value.as < std::vector<ExprAST*> > () = yystack_[0].value.as < std::vector<ExprAST*> > (); }
#line 1077 "parser.cc"
    break;

  case 46: // explist: exp
#line 194 "parser.yy"
                        { std::vector<ExprAST*> args;
                          args.push_back(yystack_[0].value.as < ExprAST* > ());
			                    yylhs.value.as < std::vector<ExprAST*> > () = args; }
#line 1085 "parser.cc"
    break;

  case 47: // explist: exp "," explist
#line 197 "parser.yy"
                        { yystack_[0].value.as < std::vector<ExprAST*> > ().insert(yystack_[0].value.as < std::vector<ExprAST*> > ().begin(), yystack_[2].value.as < ExprAST* > ()); yylhs.value.as < std::vector<ExprAST*> > () = yystack_[0].value.as < std::vector<ExprAST*> > (); }
#line 1091 "parser.cc"
    break;

  case 48: // ifexp: "if" exp "then" exp "else" exp "end"
#line 201 "parser.yy"
                                  { yylhs.value.as < ExprAST* > () = new IfExprAST(yystack_[5].value.as < ExprAST* > (), yystack_[3].value.as < ExprAST* > (), yystack_[1].value.as < ExprAST* > ());}
#line 1097 "parser.cc"
    break;

  case 49: // forexp: "for" "id" "=" exp "," exp step "in" exp "end"
#line 206 "parser.yy"
                                             { yylhs.value.as < ExprAST* > () = new ForExprAST(yystack_[8].value.as < std::string > (), yystack_[6].value.as < ExprAST* > (), yystack_[4].value.as < ExprAST* > (), yystack_[3].value.as < ExprAST* > (), yystack_[1].value.as < ExprAST* > ()); }
#line 1103 "parser.cc"
    break;

  case 50: // step: "," exp
#line 210 "parser.yy"
            { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1109 "parser.cc"
    break;

  case 51: // step: %empty
#line 211 "parser.yy"
            { yylhs.value.as < ExprAST* > () = new NumberExprAST(1.0); }
#line 1115 "parser.cc"
    break;

  case 52: // whilexp: "while" exp "in" exp "end"
#line 215 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new WhileExprAST(yystack_[3].value.as < ExprAST* > (), yystack_[1].value.as < ExprAST* > ()); }
#line 1121 "parser.cc"
    break;

  case 53: // print: "print" "(" exp ")"
#line 219 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new PrintAST(yystack_[1].value.as < ExprAST* > ()); }
#line 1127 "parser.cc"
    break;

  case 54: // varexp: "var" varlist "in" exp "end"
#line 223 "parser.yy"
                               { yylhs.value.as < ExprAST* > () = new VarExprAST(yystack_[3].value.as < std::vector<std::pair<std::string, ExprAST*>> > (), yystack_[1].value.as < ExprAST* > ()); }
#line 1133 "parser.cc"
    break;

  case 55: // varlist: pair
#line 227 "parser.yy"
                              { std::vector<std::pair<std::string, ExprAST*>> args;
                                args.push_back(yystack_[0].value.as < std::pair<std::string,ExprAST*> > ());
                                yylhs.value.as < std::vector<std::pair<std::string, ExprAST*>> > () = args; }
#line 1141 "parser.cc"
    break;

  case 56: // varlist: pair "," varlist
#line 230 "parser.yy"
                              { yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > ().insert(yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > ().begin(), yystack_[2].value.as < std::pair<std::string,ExprAST*> > ()); yylhs.value.as < std::vector<std::pair<std::string, ExprAST*>> > () = yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > (); }
#line 1147 "parser.cc"
    break;

  case 57: // varlist: arraydef
#line 231 "parser.yy"
                              { std::vector<std::pair<std::string, ExprAST*>> args;
                                args.push_back(yystack_[0].value.as < std::pair<std::string,ExprAST*> > ());
                                yylhs.value.as < std::vector<std::pair<std::string, ExprAST*>> > () = args; }
#line 1155 "parser.cc"
    break;

  case 58: // varlist: arraydef "," varlist
#line 234 "parser.yy"
                              { yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > ().insert(yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > ().begin(), yystack_[2].value.as < std::pair<std::string,ExprAST*> > ()); yylhs.value.as < std::vector<std::pair<std::string, ExprAST*>> > () = yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > (); }
#line 1161 "parser.cc"
    break;

  case 59: // pair: "id"
#line 238 "parser.yy"
                          { yylhs.value.as < std::pair<std::string,ExprAST*> > () = std::make_pair(yystack_[0].value.as < std::string > (), new NumberExprAST(0.0)); }
#line 1167 "parser.cc"
    break;

  case 60: // pair: "id" "=" exp
#line 239 "parser.yy"
                          { yylhs.value.as < std::pair<std::string,ExprAST*> > () = std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExprAST* > ()); }
#line 1173 "parser.cc"
    break;

  case 61: // assignment: "id" "=" exp
#line 243 "parser.yy"
                            { yylhs.value.as < ExprAST* > () = new BinaryExprAST('=', new VariableExprAST(yystack_[2].value.as < std::string > ()), yystack_[0].value.as < ExprAST* > ()); }
#line 1179 "parser.cc"
    break;

  case 62: // assignment: "id" "[" exp "]" "=" exp
#line 244 "parser.yy"
                            { yylhs.value.as < ExprAST* > () = new ArrayAssignExprAST(yystack_[5].value.as < std::string > (), yystack_[3].value.as < ExprAST* > (), yystack_[0].value.as < ExprAST* > ()); }
#line 1185 "parser.cc"
    break;

  case 63: // arraydef: "id" "arrof" exp
#line 248 "parser.yy"
                            { yylhs.value.as < std::pair<std::string,ExprAST*> > () = std::make_pair(yystack_[2].value.as < std::string > (), yystack_[0].value.as < ExprAST* > ()); yystack_[0].value.as < ExprAST* > ()->setIsSize(); }
#line 1191 "parser.cc"
    break;

  case 64: // arrayexp: "id" "[" exp "]"
#line 252 "parser.yy"
                            { yylhs.value.as < ExprAST* > () = new ArrayExprAST(yystack_[3].value.as < std::string > (), yystack_[1].value.as < ExprAST* > ()); }
#line 1197 "parser.cc"
    break;


#line 1201 "parser.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -57;

  const signed char parser::yytable_ninf_ = -6;

  const short
  parser::yypact_[] =
  {
      59,   -13,    -4,     1,   -20,   -20,    -4,   -15,    17,    -9,
      -4,   -11,   -57,    47,   -57,    31,   -57,   -57,   420,   -57,
     -57,   -57,   -57,   -57,   -57,   -57,   -57,    -4,    32,   -57,
     -57,   360,    -4,   -57,   -57,    45,   -57,    -4,   272,    43,
      -4,   -18,    36,    64,    68,   224,    -4,    -4,    -4,   -57,
      59,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
      -4,    -4,    -4,   375,   -57,   390,    38,   420,    -4,    -4,
     405,    -4,    -4,    -4,    -9,    -9,    -4,   313,    61,   -57,
     435,   294,   -57,    -1,    -1,   -57,   -57,    -1,    34,    34,
      34,    34,    34,    34,   420,   -57,   -57,    38,    62,   249,
     329,   -57,   420,   420,   120,   -57,   -57,   146,    -4,   -57,
      56,   -57,   -57,    -4,    -4,   -57,   -57,   -57,    -4,   172,
     345,   435,   -57,    -4,    51,   420,    -4,   198,   -57
  };

  const signed char
  parser::yydefact_[] =
  {
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,    27,     0,     2,     0,     6,     7,     8,    25,
      35,    36,    40,    37,    38,    39,    41,     0,    42,    28,
      30,     0,     0,    31,    33,     0,    10,     0,     0,     0,
       0,    59,     0,    55,    57,     0,    44,     0,     0,     1,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,     0,    12,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,    45,
      61,     0,     4,    15,    14,    16,    17,    18,    22,    21,
      20,    19,    23,    24,    34,    29,    32,    12,     0,     0,
       0,    53,    60,    63,     0,    56,    58,     0,     0,    43,
      64,    13,    11,     0,     0,    54,    52,    47,     0,     0,
      51,    62,    48,     0,     0,    50,     0,     0,    49
  };

  const signed char
  parser::yypgoto_[] =
  {
     -57,   -57,    35,   -57,   -57,   -57,    76,    -8,    -2,    10,
     -57,   -22,   -57,   -57,   -57,   -57,   -57,   -57,   -56,   -57,
     -57,   -57,   -57
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    13,    14,    15,    16,    17,    36,    98,    18,    19,
      78,    79,    20,    21,   124,    22,    23,    24,    42,    43,
      25,    44,    26
  };

  const short
  parser::yytable_[] =
  {
      31,     1,    71,    27,    38,    46,    53,    54,    45,    47,
      48,    30,     2,    34,     3,    35,    72,    32,   105,   106,
      39,     6,    28,    29,     7,    63,    41,     8,     9,    10,
      65,    11,    12,    40,    50,    67,    28,    33,    70,    51,
      52,    53,    54,    55,    77,    80,    81,    49,    46,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    66,    -5,    69,     1,    73,    99,   100,    74,   102,
     103,   104,    75,    97,   107,     2,   118,     3,   109,   112,
     126,    37,     4,     5,     6,    82,   117,     7,     0,   111,
       8,     9,    10,     0,    11,    12,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,   119,   120,     0,     0,     0,   121,     0,     0,     0,
       0,   125,     0,     0,   127,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,     0,     0,     0,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,     0,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   128,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,     0,    62,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,    62,     0,
       0,     0,     0,     0,     0,     0,   113,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     0,     0,
       0,    62,     0,     0,     0,     0,     0,     0,    68,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       0,     0,     0,    62,     0,     0,   110,   108,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
       0,     0,    62,   114,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,     0,     0,    62,   123,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,     0,     0,    62,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,    64,     0,    62,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,    95,     0,    62,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,    96,     0,    62,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,   101,     0,    62,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,     0,     0,     0,    62,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61
  };

  const signed char
  parser::yycheck_[] =
  {
       2,     5,    20,    16,     6,    16,     7,     8,    10,    20,
      21,     1,    16,     3,    18,    35,    34,    16,    74,    75,
      35,    25,    35,    36,    28,    27,    35,    31,    32,    33,
      32,    35,    36,    16,     3,    37,    35,    36,    40,     5,
       6,     7,     8,     9,    46,    47,    48,     0,    16,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    16,     3,    20,     5,    29,    68,    69,     4,    71,
      72,    73,     4,    35,    76,    16,    20,    18,    17,    17,
      29,     5,    23,    24,    25,    50,   108,    28,    -1,    97,
      31,    32,    33,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,
      -1,   113,   114,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,   123,    -1,    -1,   126,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    -1,    -1,    26,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,    -1,    -1,    22,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      -1,    -1,    19,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    19,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    19,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    19,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    19,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    -1,    19,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    19,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    -1,    19,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15
  };

  const signed char
  parser::yystos_[] =
  {
       0,     5,    16,    18,    23,    24,    25,    28,    31,    32,
      33,    35,    36,    38,    39,    40,    41,    42,    45,    46,
      49,    50,    52,    53,    54,    57,    59,    16,    35,    36,
      46,    45,    16,    36,    46,    35,    43,    43,    45,    35,
      16,    35,    55,    56,    58,    45,    16,    20,    21,     0,
       3,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    19,    45,    17,    45,    16,    45,    26,    20,
      45,    20,    34,    29,     4,     4,    29,    45,    47,    48,
      45,    45,    39,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    17,    17,    35,    44,    45,
      45,    17,    45,    45,    45,    55,    55,    45,     4,    17,
      22,    44,    17,    27,     4,    30,    30,    48,    20,    45,
      45,    45,    30,     4,    51,    45,    29,    45,    30
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    37,    38,    39,    39,    40,    40,    40,    40,    41,
      42,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    50,
      51,    51,    52,    53,    54,    55,    55,    55,    55,    56,
      56,    57,    57,    58,    59
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     0,     3,     0,     1,     1,     1,     3,
       2,     4,     0,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     1,     2,     4,
       2,     2,     4,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     1,     1,     3,     7,    10,
       2,     0,     5,     4,     5,     1,     3,     1,     3,     1,
       3,     3,     6,     3,     4
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\";\"", "\",\"",
  "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"%\"", "\">\"", "\"<\"", "\">=\"",
  "\"<=\"", "\"==\"", "\"!=\"", "\"(\"", "\")\"", "\"!\"", "\":\"",
  "\"=\"", "\"[\"", "\"]\"", "\"extern\"", "\"def\"", "\"if\"", "\"then\"",
  "\"else\"", "\"for\"", "\"in\"", "\"end\"", "\"print\"", "\"var\"",
  "\"while\"", "\"arrof\"", "\"id\"", "\"number\"", "$accept", "startsymb",
  "program", "top", "definition", "external", "proto", "idseq", "exp",
  "idexp", "optexp", "explist", "ifexp", "forexp", "step", "whilexp",
  "print", "varexp", "varlist", "pair", "assignment", "arraydef",
  "arrayexp", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,   119,   119,   122,   123,   127,   128,   129,   130,   134,
     138,   142,   146,   148,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   183,   184,   188,   191,   194,   197,   201,   206,
     210,   211,   215,   219,   223,   227,   230,   231,   234,   238,
     239,   243,   244,   248,   252
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1813 "parser.cc"

#line 254 "parser.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
