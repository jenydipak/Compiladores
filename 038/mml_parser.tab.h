/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MML_PARSER_TAB_H_INCLUDED
# define YY_YY_MML_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    tTYPE_INT = 258,               /* tTYPE_INT  */
    tTYPE_DOUBLE = 259,            /* tTYPE_DOUBLE  */
    tTYPE_STRING = 260,            /* tTYPE_STRING  */
    tTYPE_VOID = 261,              /* tTYPE_VOID  */
    tTYPE_RETURN = 262,            /* tTYPE_RETURN  */
    tBEGIN = 263,                  /* tBEGIN  */
    tEND = 264,                    /* tEND  */
    tDECL_FOREIGN = 265,           /* tDECL_FOREIGN  */
    tDECL_FORWARD = 266,           /* tDECL_FORWARD  */
    tDECL_PUBLIC = 267,            /* tDECL_PUBLIC  */
    tDECL_AUTO = 268,              /* tDECL_AUTO  */
    tDECL_PRIVATE = 269,           /* tDECL_PRIVATE  */
    tIF = 270,                     /* tIF  */
    tELIF = 271,                   /* tELIF  */
    tELSE = 272,                   /* tELSE  */
    tWHILE = 273,                  /* tWHILE  */
    tSTOP = 274,                   /* tSTOP  */
    tNEXT = 275,                   /* tNEXT  */
    tRETURN = 276,                 /* tRETURN  */
    tPRINT = 277,                  /* tPRINT  */
    tPRINT_LN = 278,               /* tPRINT_LN  */
    tINPUT = 279,                  /* tINPUT  */
    tSIZEOF = 280,                 /* tSIZEOF  */
    tNOT = 281,                    /* tNOT  */
    tAND = 282,                    /* tAND  */
    tOR = 283,                     /* tOR  */
    tINTEGER = 284,                /* tINTEGER  */
    tREAL = 285,                   /* tREAL  */
    tIDENTIFIER = 286,             /* tIDENTIFIER  */
    tSTRING = 287,                 /* tSTRING  */
    tNULLPTR = 288,                /* tNULLPTR  */
    tEQ = 289,                     /* tEQ  */
    tNE = 290,                     /* tNE  */
    tGE = 291,                     /* tGE  */
    tLE = 292,                     /* tLE  */
    tUNARY = 293                   /* tUNARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "mml_parser.y"

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

#line 124 "mml_parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (std::shared_ptr<cdk::compiler> compiler);


#endif /* !YY_YY_MML_PARSER_TAB_H_INCLUDED  */
