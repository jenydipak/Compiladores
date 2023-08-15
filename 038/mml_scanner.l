%option c++ prefix="mml_scanner_" outfile="mml_scanner.cpp"
%option stack noyywrap yylineno 8bit debug
%{ 
// make relevant includes before including the parser's tab file
#include <string>
#include <sstream>
#include <cdk/ast/sequence_node.h>
#include <cdk/ast/expression_node.h>
#include <cdk/ast/lvalue_node.h>
#include "mml_parser.tab.h"

// don't change this
#define yyerror LexerError


%}
%x X_STRING X_BACKSLASH
%x X_COMMENT
%%
  yydebug=1; set_debug(1);


  /* ==================================================== */
  /* ====[          3.2 - COMENTARIOS               ]==== */
  /* ==================================================== */

"//".*$                 ; /* ignore explanatory comments - matches whole line*/

"/*"                    yy_push_state(X_COMMENT);
<X_COMMENT>"/*"         yy_push_state(X_COMMENT); /* DBT - Check if this one is necesary */
<X_COMMENT>"*/"         yy_pop_state();
<X_COMMENT>.|n          ; /* ignore operational comments */


  /* ==================================================== */
  /* ====[           3.4 - TIPOS                    ]==== */
  /* ====[           3.8 - LITERAIS: PONTEIROS      ]==== */
  /* ==================================================== */

"int"                 return tTYPE_INT;
"double"              return tTYPE_DOUBLE;
"string"              return tTYPE_STRING;
"void"                return tTYPE_VOID;
[\[\]]                return *yytext;

"null"                return tNULLPTR;


  /* ==================================================== */
  /* ====[      3.5 - OPERADORES DE EXPRESSOES      ]==== */
  /* ==================================================== */

">="                   return tGE; 
"<="                   return tLE; 
"=="                   return tEQ; 
"!="                   return tNE; 

"~"                    return tNOT;
"&&"                   return tAND;
"||"                   return tOR;

[\[\](),?]             return *yytext;
[-+*/%~<>@?=]          return *yytext;

"input"                return tINPUT;
"begin"                return tBEGIN; 
"end"                  return tEND; 
"sizeof"               return tSIZEOF;

  /* ==================================================== */
  /* ====[       4.4 Declaração de variáveis        ]==== */
  /* ====[       4.5 - Simbolos globais             ]==== */
  /* ==================================================== */

"foreign"             return tDECL_FOREIGN;
"forward"             return tDECL_FORWARD;
"public"              return tDECL_PUBLIC;
"auto"                return tDECL_AUTO;

  /* ==================================================== */
  /* ====[      6 - INSTRUÇOES                      ]==== */
  /* ==================================================== */

"while"                return tWHILE; 
"if"                   return tIF; 
"elif"                 return tELIF; 
"else"                 return tELSE; 
"!!"                   return tPRINT_LN; 
"!"                    return tPRINT; 
"stop"                 return tSTOP;
"next"                 return tNEXT;
"return"               return tRETURN;
"->"                   return tTYPE_RETURN;

  /* ==================================================== */
  /* ====[      3.7 - IDENTIFICADORES               ]==== */
  /* ==================================================== */

[A-Za-z][A-Za-z0-9]*  yylval.s = new std::string(yytext); return tIDENTIFIER;


  /* ==================================================== */
  /* ====[      3.8.1 - LIT: INTEIROS               ]==== */
  /* ==================================================== */

 /* Literais inteiros em base 8 */
0[0-7]+                {
                        yylval.i = strtoul(yytext, nullptr, 8); 
                        if (errno == ERANGE) 
                          yyerror("Overflow - base 8 number too big"); 
                        else 
                          return tINTEGER;
                       }
0[0-9]+                yyerror("Invalid value for number - base 8.");

0|[1-9][0-9]*          {
                        yylval.i = strtoul(yytext, nullptr, 10); 
                        if (errno == ERANGE) 
                          yyerror("Overflow - base 10 number too big"); 
                        else 
                          return tINTEGER;
                       }

[-()<>=+*/%;{}.]       return *yytext;


  /* ==================================================== */
  /* ====[      3.8.2 - LIT: REAIS       ]==== */
  /* ==================================================== */

([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)([eE][-+]?[0-9]+)?   {
                                                    yylval.d = strtod(yytext, NULL);
                                                    if (errno == ERANGE) 
                                                      yyerror("Overflow - Out of range");
                                                    else 
                                                      return tREAL;
                                                    }
  

  /* ==================================================== */
  /* ====[      3.8.3 - LIT: CADEIAS DE CARACTERES       ]==== */
  /* ==================================================== */

\"                                           yy_push_state(X_STRING); yylval.s = new std::string("");
<X_STRING>\\                                 yy_push_state(X_BACKSLASH);
<X_STRING>\"                                 yy_pop_state(); return tSTRING;

<X_BACKSLASH>0[0-7]{2}                       yy_pop_state(); *yylval.s += std::stoul(&yytext[2], nullptr, 8);
<X_BACKSLASH>[0-7]{3}                        yy_pop_state(); *yylval.s += std::stoul(&yytext[1], nullptr, 8);
<X_BACKSLASH>0[^0-9a-fA-F][^"]*\"            yy_pop_state(); return tSTRING; /* \0 as EOF character*/
<X_BACKSLASH>n                               yy_pop_state(); *yylval.s += "\n";
<X_BACKSLASH>r                               yy_pop_state(); *yylval.s += "\r";
<X_BACKSLASH>t                               yy_pop_state(); *yylval.s += "\t";
<X_BACKSLASH>\\                              yy_pop_state(); *yylval.s += "\\";
<X_BACKSLASH>\"                              yy_pop_state(); *yylval.s += "\"";

<X_STRING>.                                  *yylval.s += yytext;

  /* ==================================================== */
  /* ====[      3.1 - CARACTERES BRANCOS            ]==== */
  /* ==================================================== */

[ \t\n\r]+               ; /* ignore whitespace */

  /* ==================================================== */
  /* ====[                 OUTROS                   ]==== */
  /* ==================================================== */

.                      yyerror("Unknown character");

%%
