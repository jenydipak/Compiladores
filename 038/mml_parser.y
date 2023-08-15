%{
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <algorithm>
#include <memory>
#include <cstring>
#include <cdk/compiler.h>
#include <cdk/types/types.h>
#include ".auto/all_nodes.h"
#define LINE                         compiler->scanner()->lineno()
#define yylex()                      compiler->scanner()->scan()
#define yyerror(compiler, s)         compiler->scanner()->error(s)
//-- don't change *any* of these --- END!
%}

%parse-param {std::shared_ptr<cdk::compiler> compiler}

%union {
  //--- don't change *any* of these: if you do, you'll break the compiler.
  YYSTYPE() : type(cdk::primitive_type::create(0, cdk::TYPE_VOID)) {}
  ~YYSTYPE() {}
  YYSTYPE(const YYSTYPE &other) { *this = other; }
  YYSTYPE& operator=(const YYSTYPE &other) { type = other.type; return *this; }

  std::shared_ptr<cdk::basic_type> type;        /* expression type */
  //-- don't change *any* of these --- END!

  int                   i;	/* integer value */
  double                d;  /*double value*/
  std::string          *s;	/* symbol name or string literal */
  cdk::basic_node      *node;	/* node pointer */
  cdk::sequence_node   *sequence;
  cdk::expression_node *expression; /* expression nodes */
  cdk::lvalue_node     *lvalue;
  mml::block_node      *block;

  std::vector<std::shared_ptr<cdk::basic_type>>  *functype;
};

%token tTYPE_INT tTYPE_DOUBLE tTYPE_STRING tTYPE_VOID tTYPE_RETURN
%token tBEGIN tEND
%token tDECL_FOREIGN tDECL_FORWARD tDECL_PUBLIC tDECL_AUTO tDECL_PRIVATE
%token tIF tELIF tELSE
%token tWHILE tSTOP tNEXT tRETURN
%token tPRINT tPRINT_LN tINPUT  
%token tSIZEOF 
%token tNOT tAND tOR 

%token <i> tINTEGER
%token <d> tREAL
%token <s> tIDENTIFIER tSTRING
%token <expression> tNULLPTR

%right '='
%left tOR
%left tAND
%nonassoc tNOT
%left tEQ tNE
%left tGE tLE '>' '<'
%left '+' '-'
%left '*' '/' '%'
%nonassoc tUNARY '?'
%nonassoc '(' '['

%type <node> instr instr_cond instr_iter false_cond var var_decl declaration program
%type <sequence> exprs 
%type <expression> expr function func_call opt_init
%type <lvalue> lval

%type <block> block inner_block
%type <sequence> vars var_decls opt_var_decls opt_instrs
%type <functype> data_types
%type <type> data_type func_type return_type
%type <s> string

%type <sequence> file declarations

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}
%%

 /* Main file ---------------------------------------------------------------- */

file : /* EMPTY */              {compiler->ast($$ = new cdk::sequence_node(LINE)); }
     | declarations             {compiler->ast($1); }
     | declarations program     {compiler->ast($$ = new cdk::sequence_node(LINE, $2, $1)); }
     | program                  {compiler->ast($1); }
     ;

declarations : declaration              { $$ = new cdk::sequence_node(LINE, $1); }
             | declarations declaration { $$ = new cdk::sequence_node(LINE, $2, $1); }

declaration : var_decl ';'                 { $$ = $1; }
            | var_decl                     { $$ = $1; }
            ;

 /* Main file - END----------------------------------------------------------- */


 /* Functions ---------------------------------------------------------------- */

program	: tBEGIN inner_block tEND { compiler->ast(new mml::program_node(LINE, $2)); }
	      ;

function  : '(' vars ')' tTYPE_RETURN data_type block  { $$ = new mml::function_definition_node(LINE, $5, $2, $6); }
          | '('      ')' tTYPE_RETURN data_type block  { $$ = new mml::function_definition_node(LINE, $4, new cdk::sequence_node(LINE), $5); }
          ;

func_call : lval '(' exprs ')'            { $$ = new mml::function_call_node(LINE, new cdk::rvalue_node(LINE, $1), $3); }
          | lval '('       ')'            { $$ = new mml::function_call_node(LINE, new cdk::rvalue_node(LINE, $1)); }
          | '@' '(' exprs ')'             { $$ = new mml::function_call_node(LINE, nullptr, $3); }
          | '@' '('       ')'             { $$ = new mml::function_call_node(LINE, nullptr); }
          | '(' expr ')'  '(' exprs ')'   { $$ = new mml::function_call_node(LINE, $2, $5); }
          | '(' expr ')'  '('       ')'   { $$ = new mml::function_call_node(LINE, $2); }
          ;

 /* Functions - END------------------------------------------------------------ */


 /* Blocks ------------------------------------------------------------------- */

block : '{' inner_block '}'              { $$ = $2; }
      ;

inner_block : opt_var_decls opt_instrs    { $$ = new mml::block_node(LINE, $1, $2); }
            ;                  

opt_var_decls : /* EMPTY */               { $$ = NULL; }
              | var_decls                 { $$ = $1; }
              ;

opt_instrs : /* EMPTY */           { $$ = new cdk::sequence_node(LINE); }
           | opt_instrs instr      { $$ = new cdk::sequence_node(LINE, $2, $1); }
           ;

 /* Blocks - END-------------------------------------------------------------- */


 /* Types -------------------------------------------------------------------- */

data_types : /* EMPTY */                     { $$ = new std::vector<std::shared_ptr<cdk::basic_type>>();}  
           | data_type                       { $$ = new std::vector<std::shared_ptr<cdk::basic_type>>(); $$->insert($$->begin(), $1);}      
           | data_type ',' data_types        { $$ = $3; $$->insert($$->begin(), $1); }
           ;

data_type : tTYPE_STRING                     { $$ = cdk::primitive_type::create(4, cdk::TYPE_STRING); }
          | tTYPE_INT                        { $$ = cdk::primitive_type::create(4, cdk::TYPE_INT); }
          | tTYPE_DOUBLE                     { $$ = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
          | '[' data_type ']'                { $$ = cdk::reference_type::create(4, $2); }
          | func_type                        { $$ = $1; }
          ;

func_type : return_type '<' data_types '>'   { $$ = cdk::functional_type::create(*$3, $1);}	
          ;

return_type : data_type                       { $$ = $1; }
            | tTYPE_VOID                      { $$ = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
            ;

string : tSTRING                              { $$ = $1; }
       | string tSTRING                       { $$ = new std::string(*$1 + *$2); delete $1; delete $2; }
       ;

 /* Types - END -------------------------------------------------------------- */


 /* Variables ---------------------------------------------------------------- */

vars      : var                              { $$ = new cdk::sequence_node(LINE, $1); }
          | vars ',' var                     { $$ = new cdk::sequence_node(LINE, $3, $1); }
          ;

var       : data_type tIDENTIFIER            { $$ = new mml::variable_declaration_node(LINE, tDECL_PRIVATE, $1, *$2, nullptr); }
          ;

 /* Variables - END----------------------------------------------------------- */


 /* Instructions ------------------------------------------------------------- */

instr : expr                             { $$ = new mml::evaluation_node(LINE, $1); }
      | instr_cond                 { $$ = new cdk::sequence_node(LINE, $1); }
      | instr_iter                 { $$ = new cdk::sequence_node(LINE, $1); }
      | exprs tPRINT                    { $$ = new mml::print_node(LINE, $1, false); }
      | exprs tPRINT_LN                 { $$ = new mml::print_node(LINE, $1, true); }
      | tSTOP ';'                        { $$ = new mml::stop_node(LINE); }
      | tSTOP tINTEGER ';'               { $$ = new mml::stop_node(LINE, $2); }
      | tNEXT ';'                        { $$ = new mml::next_node(LINE); }
      | tNEXT tINTEGER ';'               { $$ = new mml::next_node(LINE, $2); }
      | tRETURN ';'                      { $$ = new mml::return_node(LINE, nullptr); }
      | tRETURN expr ';'                 { $$ = new mml::return_node(LINE, $2); }
      | block                            { $$ = $1; }
      ;

instr_cond : tIF '(' expr ')' instr               { $$ = new mml::if_node(LINE, $3, $5); }
           | tIF '(' expr ')' instr false_cond    { $$ = new mml::if_else_node(LINE, $3, $5, $6); }
           ;

instr_iter : tWHILE '(' expr ')' instr            { $$ = new mml::while_node(LINE, $3, $5); }
           ;

false_cond : tELSE instr                          { $$ = $2; }
           | tELIF '(' expr ')' instr             { $$ = new mml::if_node(LINE, $3, $5); }
           | tELIF '(' expr ')' instr false_cond  { $$ = new mml::if_else_node(LINE, $3, $5, $6); }
           ;

 /* Instructions - END-------------------------------------------------------- */


/* Variable declarations ----------------------------------------------------- */

opt_init : /* EMPTY */                { $$ = nullptr; }
         | '=' expr                   { $$ = $2; }
         ;

var_decls : var_decl ';'                  { $$ = new cdk::sequence_node(LINE, $1); }
          | var_decls var_decl ';'      { $$ = new cdk::sequence_node(LINE, $2, $1); }
          ;

var_decl : tDECL_FORWARD data_type  tIDENTIFIER           { $$ = new mml::variable_declaration_node(LINE, tDECL_PUBLIC, $2, *$3, nullptr); }
         |               data_type  tIDENTIFIER opt_init  { $$ = new mml::variable_declaration_node(LINE, tDECL_PRIVATE, $1, *$2, $3); }
         | tDECL_PUBLIC  data_type  tIDENTIFIER opt_init  { $$ = new mml::variable_declaration_node(LINE, tDECL_PUBLIC, $2, *$3, $4); }
         | tDECL_PUBLIC  tDECL_AUTO tIDENTIFIER '=' expr  { $$ = new mml::variable_declaration_node(LINE, tDECL_PUBLIC, nullptr, *$3, $5); }
         |               tDECL_AUTO tIDENTIFIER '=' expr  { $$ = new mml::variable_declaration_node(LINE, tDECL_PUBLIC, nullptr, *$2, $4); }
         | tDECL_PUBLIC             tIDENTIFIER '=' expr  { $$ = new mml::variable_declaration_node(LINE, tDECL_PUBLIC, nullptr, *$2, $4); }
         | tDECL_FOREIGN data_type  tIDENTIFIER           { $$ = new mml::variable_declaration_node(LINE, tDECL_FOREIGN, $2, *$3, nullptr); }
         ;


/* Variable declarations - END------------------------------------------------ */


 /* Expressions -------------------------------------------------------------- */

expr : tINTEGER                  { $$ = new cdk::integer_node(LINE, $1); }
     | tREAL                     { $$ = new cdk::double_node(LINE, $1); }
     | string                    { $$ = new cdk::string_node(LINE, $1); }
     | tNULLPTR                  { $$ = new mml::null_pointer_node(LINE); }
     | lval                      { $$ = new cdk::rvalue_node(LINE, $1); }  //FIXME
     | lval '=' expr             { $$ = new cdk::assignment_node(LINE, $1, $3); }
     | lval '?'                { $$ = new mml::address_of_node(LINE, $1); }
     | expr '+' expr	         { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr '-' expr	         { $$ = new cdk::sub_node(LINE, $1, $3); }
     | expr '*' expr	         { $$ = new cdk::mul_node(LINE, $1, $3); }
     | expr '/' expr	         { $$ = new cdk::div_node(LINE, $1, $3); }
     | expr '%' expr	         { $$ = new cdk::mod_node(LINE, $1, $3); }
     | expr '<' expr	         { $$ = new cdk::lt_node(LINE, $1, $3); }
     | expr '>' expr	         { $$ = new cdk::gt_node(LINE, $1, $3); }
     | expr tGE expr	         { $$ = new cdk::ge_node(LINE, $1, $3); }
     | expr tLE expr             { $$ = new cdk::le_node(LINE, $1, $3); }
     | expr tNE expr	         { $$ = new cdk::ne_node(LINE, $1, $3); }
     | expr tEQ expr	         { $$ = new cdk::eq_node(LINE, $1, $3); }
     | expr tAND expr          { $$ = new cdk::add_node(LINE, $1, $3); }
     | expr tOR expr           { $$ = new cdk::or_node(LINE, $1, $3); }
     | '-' expr %prec tUNARY     { $$ = new cdk::neg_node(LINE, $2); }
     | '+' expr %prec tUNARY     { $$ = new mml::identity_node(LINE, $2); }
     | tNOT expr               { $$ = new cdk::not_node(LINE, $2); }
     | tINPUT                  { $$ = new mml::input_node(LINE); }
     | tSIZEOF '(' expr ')'    { $$ = new mml::sizeof_node(LINE, $3); }
     | '(' expr ')'            { $$ = $2; }
     | '[' expr ']'            { $$ = new mml::stack_alloc_node(LINE, $2); }
     | func_call               { $$ = $1; }
     | function                { $$ = $1; }
     ;

exprs : expr                       { $$ = new cdk::sequence_node(LINE, $1); }
      | exprs ',' expr             { $$ = new cdk::sequence_node(LINE, $3, $1); }
      ;

/* Expressions - END--------------------------------------------------------- */


 /* Others ------------------------------------------------------------------- */
lval : tIDENTIFIER             { $$ = new cdk::variable_node(LINE, $1); }
     | lval '[' expr ']'        { $$ = new mml::index_node(LINE, new cdk::rvalue_node(LINE, $1), $3); }
     ;

 /* Others - END-------------------------------------------------------------- */

%%
