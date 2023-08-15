/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mml_parser.y"

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

#line 85 "mml_parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "mml_parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tTYPE_INT = 3,                  /* tTYPE_INT  */
  YYSYMBOL_tTYPE_DOUBLE = 4,               /* tTYPE_DOUBLE  */
  YYSYMBOL_tTYPE_STRING = 5,               /* tTYPE_STRING  */
  YYSYMBOL_tTYPE_VOID = 6,                 /* tTYPE_VOID  */
  YYSYMBOL_tTYPE_RETURN = 7,               /* tTYPE_RETURN  */
  YYSYMBOL_tBEGIN = 8,                     /* tBEGIN  */
  YYSYMBOL_tEND = 9,                       /* tEND  */
  YYSYMBOL_tDECL_FOREIGN = 10,             /* tDECL_FOREIGN  */
  YYSYMBOL_tDECL_FORWARD = 11,             /* tDECL_FORWARD  */
  YYSYMBOL_tDECL_PUBLIC = 12,              /* tDECL_PUBLIC  */
  YYSYMBOL_tDECL_AUTO = 13,                /* tDECL_AUTO  */
  YYSYMBOL_tDECL_PRIVATE = 14,             /* tDECL_PRIVATE  */
  YYSYMBOL_tIF = 15,                       /* tIF  */
  YYSYMBOL_tELIF = 16,                     /* tELIF  */
  YYSYMBOL_tELSE = 17,                     /* tELSE  */
  YYSYMBOL_tWHILE = 18,                    /* tWHILE  */
  YYSYMBOL_tSTOP = 19,                     /* tSTOP  */
  YYSYMBOL_tNEXT = 20,                     /* tNEXT  */
  YYSYMBOL_tRETURN = 21,                   /* tRETURN  */
  YYSYMBOL_tPRINT = 22,                    /* tPRINT  */
  YYSYMBOL_tPRINT_LN = 23,                 /* tPRINT_LN  */
  YYSYMBOL_tINPUT = 24,                    /* tINPUT  */
  YYSYMBOL_tSIZEOF = 25,                   /* tSIZEOF  */
  YYSYMBOL_tNOT = 26,                      /* tNOT  */
  YYSYMBOL_tAND = 27,                      /* tAND  */
  YYSYMBOL_tOR = 28,                       /* tOR  */
  YYSYMBOL_tINTEGER = 29,                  /* tINTEGER  */
  YYSYMBOL_tREAL = 30,                     /* tREAL  */
  YYSYMBOL_tIDENTIFIER = 31,               /* tIDENTIFIER  */
  YYSYMBOL_tSTRING = 32,                   /* tSTRING  */
  YYSYMBOL_tNULLPTR = 33,                  /* tNULLPTR  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_tEQ = 35,                       /* tEQ  */
  YYSYMBOL_tNE = 36,                       /* tNE  */
  YYSYMBOL_tGE = 37,                       /* tGE  */
  YYSYMBOL_tLE = 38,                       /* tLE  */
  YYSYMBOL_39_ = 39,                       /* '>'  */
  YYSYMBOL_40_ = 40,                       /* '<'  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '*'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_45_ = 45,                       /* '%'  */
  YYSYMBOL_tUNARY = 46,                    /* tUNARY  */
  YYSYMBOL_47_ = 47,                       /* '?'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* '['  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* '@'  */
  YYSYMBOL_53_ = 53,                       /* '{'  */
  YYSYMBOL_54_ = 54,                       /* '}'  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_file = 58,                      /* file  */
  YYSYMBOL_declarations = 59,              /* declarations  */
  YYSYMBOL_declaration = 60,               /* declaration  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_function = 62,                  /* function  */
  YYSYMBOL_func_call = 63,                 /* func_call  */
  YYSYMBOL_block = 64,                     /* block  */
  YYSYMBOL_inner_block = 65,               /* inner_block  */
  YYSYMBOL_opt_var_decls = 66,             /* opt_var_decls  */
  YYSYMBOL_opt_instrs = 67,                /* opt_instrs  */
  YYSYMBOL_data_types = 68,                /* data_types  */
  YYSYMBOL_data_type = 69,                 /* data_type  */
  YYSYMBOL_func_type = 70,                 /* func_type  */
  YYSYMBOL_return_type = 71,               /* return_type  */
  YYSYMBOL_string = 72,                    /* string  */
  YYSYMBOL_vars = 73,                      /* vars  */
  YYSYMBOL_var = 74,                       /* var  */
  YYSYMBOL_instr = 75,                     /* instr  */
  YYSYMBOL_instr_cond = 76,                /* instr_cond  */
  YYSYMBOL_instr_iter = 77,                /* instr_iter  */
  YYSYMBOL_false_cond = 78,                /* false_cond  */
  YYSYMBOL_opt_init = 79,                  /* opt_init  */
  YYSYMBOL_var_decls = 80,                 /* var_decls  */
  YYSYMBOL_var_decl = 81,                  /* var_decl  */
  YYSYMBOL_expr = 82,                      /* expr  */
  YYSYMBOL_exprs = 83,                     /* exprs  */
  YYSYMBOL_lval = 84                       /* lval  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 77 "mml_parser.y"

//-- The rules below will be included in yyparse, the main parsing function.

#line 207 "mml_parser.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   570

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    45,     2,     2,
      48,    51,    43,    41,    55,    42,     2,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
      40,    34,    39,    47,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    49,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    35,
      36,    37,    38,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    84,    84,    85,    86,    87,    90,    91,    93,    94,
     102,   105,   106,   109,   110,   111,   112,   113,   114,   122,
     125,   128,   129,   132,   133,   141,   142,   143,   146,   147,
     148,   149,   150,   153,   156,   157,   160,   161,   169,   170,
     173,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   195,   196,   199,   202,   203,   204,   212,
     213,   216,   217,   220,   221,   222,   223,   224,   225,   226,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   266,
     267,   274,   275
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tTYPE_INT",
  "tTYPE_DOUBLE", "tTYPE_STRING", "tTYPE_VOID", "tTYPE_RETURN", "tBEGIN",
  "tEND", "tDECL_FOREIGN", "tDECL_FORWARD", "tDECL_PUBLIC", "tDECL_AUTO",
  "tDECL_PRIVATE", "tIF", "tELIF", "tELSE", "tWHILE", "tSTOP", "tNEXT",
  "tRETURN", "tPRINT", "tPRINT_LN", "tINPUT", "tSIZEOF", "tNOT", "tAND",
  "tOR", "tINTEGER", "tREAL", "tIDENTIFIER", "tSTRING", "tNULLPTR", "'='",
  "tEQ", "tNE", "tGE", "tLE", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "tUNARY", "'?'", "'('", "'['", "';'", "')'", "'@'", "'{'", "'}'",
  "','", "']'", "$accept", "file", "declarations", "declaration",
  "program", "function", "func_call", "block", "inner_block",
  "opt_var_decls", "opt_instrs", "data_types", "data_type", "func_type",
  "return_type", "string", "vars", "var", "instr", "instr_cond",
  "instr_iter", "false_cond", "opt_init", "var_decls", "var_decl", "expr",
  "exprs", "lval", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-100)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,  -150,  -150,  -150,  -150,    60,    31,    31,   123,   -17,
      31,    23,     5,  -150,  -150,     7,  -150,     8,    26,    68,
    -150,    60,    40,    47,    61,    64,    76,    82,    90,    69,
    -150,  -150,  -150,    96,    31,  -150,  -150,   180,    66,  -150,
    -150,  -150,    97,   354,    96,   354,  -150,   354,  -150,    94,
     -28,    86,    89,   -10,    -7,   268,  -150,    93,   354,  -150,
    -150,  -150,  -150,  -150,   354,   354,   114,   354,   104,    60,
    -150,  -150,  -150,   110,  -150,  -150,  -150,   203,   -16,    -2,
    -150,   354,   486,  -150,   486,   486,  -150,    31,   354,   354,
     103,  -150,   107,  -150,  -150,   467,   354,   516,  -150,  -150,
     145,   152,   129,    28,  -150,   372,   224,   282,   113,  -150,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   354,  -150,  -150,   354,   354,  -150,   311,   354,
     486,  -150,   391,   410,  -150,  -150,  -150,   429,    31,  -150,
     154,    31,   120,  -150,  -150,   486,    33,  -150,   516,   505,
     525,   525,    14,    14,    14,    14,    78,    78,  -150,  -150,
    -150,   486,   486,  -150,    34,   246,   180,   180,  -150,   126,
      31,  -150,   325,  -150,  -150,  -150,    45,  -150,  -150,   126,
    -150,    36,   132,   180,  -150,  -150,  -150,   354,  -150,   448,
     180,    45,  -150
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    29,    30,    28,    35,    21,     0,     0,     0,     0,
       0,     0,     3,     6,     5,    34,    32,     0,     9,     0,
      23,    22,     0,    34,    34,     0,     0,    34,     0,    34,
       1,     7,     4,    59,    25,     8,    10,    20,     0,    61,
      69,    63,     0,     0,    59,     0,    31,     0,    64,     0,
      26,     0,     0,     0,     0,     0,    93,     0,     0,    70,
      71,   101,    36,    73,     0,     0,     0,     0,     0,    21,
      98,    97,    52,    72,    24,    42,    43,    41,     0,    74,
      62,     0,    68,    65,    67,    60,    33,    25,     0,     0,
       0,    46,     0,    48,    50,     0,     0,    92,    91,    90,
       0,     0,    34,     0,    38,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,     0,    76,     0,     0,
      66,    27,     0,     0,    47,    49,    51,     0,     0,    40,
       0,     0,    95,    96,    16,    99,     0,    19,    88,    89,
      87,    86,    84,    85,    83,    82,    77,    78,    79,    80,
      81,   100,    75,    14,     0,     0,     0,     0,    94,    34,
       0,    39,     0,    15,    13,   102,    53,    55,    12,    34,
      18,     0,     0,     0,    54,    11,    17,     0,    56,     0,
       0,    57,    58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,   169,   170,  -150,  -150,  -149,   115,  -150,
    -150,    98,    -6,  -150,  -150,  -150,  -150,    42,  -141,  -150,
    -150,    -3,   146,  -150,     0,   -14,  -104,  -150
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    70,    71,    72,    19,    20,
      37,    49,    15,    16,    17,    73,   103,   104,    74,    75,
      76,   184,    48,    21,    18,    77,    78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    24,    27,   146,    29,    22,   123,   124,     1,     2,
       3,     4,   -34,     5,    28,     6,     7,     8,     9,    90,
     178,    38,    92,    30,   164,   176,   177,    87,    50,    82,
     185,    84,   126,    85,     1,     2,     3,     4,    33,   125,
      91,    95,   188,    93,    97,   127,   128,   129,    34,   191,
      98,    99,   105,   106,    10,   118,   119,   120,   121,   122,
     102,   182,   183,     1,     2,     3,     4,   130,   181,    22,
       6,     7,     8,     9,   132,   133,    35,    36,    40,   140,
      10,    50,   137,   141,   173,   174,   106,   186,   125,   125,
      39,   125,    41,   145,    29,    42,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,    10,
      43,   161,   162,    44,   145,   165,    80,     1,     2,     3,
       4,   120,   121,   122,    45,    46,     1,     2,     3,     4,
      47,    81,   169,    86,    88,   102,    25,    89,    56,    57,
      58,    96,   109,    59,    60,    61,    62,    63,     1,     2,
       3,     4,   107,   134,    26,    64,    65,   135,   145,   138,
     139,   170,    66,   100,   179,   101,    68,   147,   172,    56,
      57,    58,    10,   189,    59,    60,    61,    62,    63,    69,
     187,    31,    32,   171,   108,   131,    64,    65,   192,     0,
      83,     0,     0,    66,   100,    51,     0,    68,    52,    53,
      54,    55,     0,     0,    56,    57,    58,     0,     0,    59,
      60,    61,    62,    63,     0,     0,     0,     0,     0,     0,
       0,    64,    65,     0,     0,   -99,   -99,     0,    66,    67,
     110,   111,    68,    69,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,   110,   111,     0,     0,     0,     0,     0,   -99,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,   110,   111,     0,     0,     0,     0,     0,
     143,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    56,    57,    58,     0,     0,    59,    60,    61,
      62,    63,   175,     0,     0,     0,    56,    57,    58,    64,
      65,    59,    60,    61,    62,    63,    66,    67,    94,     0,
      68,     0,     0,    64,    65,     0,     0,     0,     0,     0,
      66,    67,     0,   144,    68,    56,    57,    58,     0,     0,
      59,    60,    61,    62,    63,     0,     0,     0,     0,    56,
      57,    58,    64,    65,    59,    60,    61,    62,    63,    66,
      67,     0,   163,    68,     0,     0,    64,    65,     0,     0,
       0,     0,     0,    66,    67,     0,   180,    68,    56,    57,
      58,     0,     0,    59,    60,    61,    62,    63,     0,     0,
       0,     0,     0,     0,     0,    64,    65,     0,     0,   110,
     111,     0,    66,    67,     0,     0,    68,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   110,   111,
       0,     0,     0,   142,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   110,   111,     0,
       0,     0,   166,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   110,   111,     0,     0,
       0,   167,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   110,   111,     0,     0,     0,
     168,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   110,   111,     0,     0,     0,   190,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   110,   111,     0,     0,   136,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   110,     0,     0,     0,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   114,   115,   116,   117,   118,   119,   120,   121,
     122
};

static const yytype_int16 yycheck[] =
{
       6,     7,     8,   107,    10,     5,    22,    23,     3,     4,
       5,     6,    40,     8,    31,    10,    11,    12,    13,    29,
     169,    21,    29,     0,   128,   166,   167,    55,    34,    43,
     179,    45,    34,    47,     3,     4,     5,     6,    31,    55,
      50,    55,   183,    50,    58,    47,    48,    49,    40,   190,
      64,    65,    66,    67,    49,    41,    42,    43,    44,    45,
      66,    16,    17,     3,     4,     5,     6,    81,   172,    69,
      10,    11,    12,    13,    88,    89,    50,     9,    31,    51,
      49,    87,    96,    55,    51,    51,   100,    51,    55,    55,
      50,    55,    31,   107,   100,    31,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    49,
      34,   125,   126,    31,   128,   129,    50,     3,     4,     5,
       6,    43,    44,    45,    34,    56,     3,     4,     5,     6,
      34,    34,   138,    39,    48,   141,    13,    48,    24,    25,
      26,    48,    32,    29,    30,    31,    32,    33,     3,     4,
       5,     6,    48,    50,    31,    41,    42,    50,   172,     7,
      31,     7,    48,    49,   170,    51,    52,    54,    48,    24,
      25,    26,    49,   187,    29,    30,    31,    32,    33,    53,
      48,    12,    12,   141,    69,    87,    41,    42,   191,    -1,
      44,    -1,    -1,    48,    49,    15,    -1,    52,    18,    19,
      20,    21,    -1,    -1,    24,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    42,    -1,    -1,    22,    23,    -1,    48,    49,
      27,    28,    52,    53,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    55,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
      56,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    24,    25,    26,    -1,    -1,    29,    30,    31,
      32,    33,    56,    -1,    -1,    -1,    24,    25,    26,    41,
      42,    29,    30,    31,    32,    33,    48,    49,    50,    -1,
      52,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    49,    -1,    51,    52,    24,    25,    26,    -1,    -1,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    24,
      25,    26,    41,    42,    29,    30,    31,    32,    33,    48,
      49,    -1,    51,    52,    -1,    -1,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    49,    -1,    51,    52,    24,    25,
      26,    -1,    -1,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    27,
      28,    -1,    48,    49,    -1,    -1,    52,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    27,    28,
      -1,    -1,    -1,    51,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    27,    28,    -1,
      -1,    -1,    51,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    27,    28,    -1,    -1,
      -1,    51,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    27,    28,    -1,    -1,    -1,
      51,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    27,    28,    -1,    -1,    -1,    51,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    27,    28,    -1,    -1,    50,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     8,    10,    11,    12,    13,
      49,    58,    59,    60,    61,    69,    70,    71,    81,    65,
      66,    80,    81,    69,    69,    13,    31,    69,    31,    69,
       0,    60,    61,    31,    40,    50,     9,    67,    81,    50,
      31,    31,    31,    34,    31,    34,    56,    34,    79,    68,
      69,    15,    18,    19,    20,    21,    24,    25,    26,    29,
      30,    31,    32,    33,    41,    42,    48,    49,    52,    53,
      62,    63,    64,    72,    75,    76,    77,    82,    83,    84,
      50,    34,    82,    79,    82,    82,    39,    55,    48,    48,
      29,    50,    29,    50,    50,    82,    48,    82,    82,    82,
      49,    51,    69,    73,    74,    82,    82,    48,    65,    32,
      27,    28,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    22,    23,    55,    34,    47,    48,    49,
      82,    68,    82,    82,    50,    50,    50,    82,     7,    31,
      51,    55,    51,    56,    51,    82,    83,    54,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    51,    83,    82,    51,    51,    51,    69,
       7,    74,    48,    51,    51,    56,    75,    75,    64,    69,
      51,    83,    16,    17,    78,    64,    51,    48,    75,    82,
      51,    75,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    58,    58,    59,    59,    60,    60,
      61,    62,    62,    63,    63,    63,    63,    63,    63,    64,
      65,    66,    66,    67,    67,    68,    68,    68,    69,    69,
      69,    69,    69,    70,    71,    71,    72,    72,    73,    73,
      74,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    76,    76,    77,    78,    78,    78,    79,
      79,    80,    80,    81,    81,    81,    81,    81,    81,    81,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    83,
      83,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     2,     1,     1,     2,     2,     1,
       3,     6,     5,     4,     3,     4,     3,     6,     5,     3,
       2,     0,     1,     0,     2,     0,     1,     3,     1,     1,
       1,     3,     1,     4,     1,     1,     1,     2,     1,     3,
       2,     1,     1,     1,     2,     2,     2,     3,     2,     3,
       2,     3,     1,     5,     6,     5,     2,     5,     6,     0,
       2,     2,     3,     3,     3,     4,     5,     4,     4,     3,
       1,     1,     1,     1,     1,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     1,     4,     3,     3,     1,     1,     1,
       3,     1,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (compiler, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, compiler); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (compiler);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, compiler);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, std::shared_ptr<cdk::compiler> compiler)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], compiler);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, compiler); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, std::shared_ptr<cdk::compiler> compiler)
{
  YY_USE (yyvaluep);
  YY_USE (compiler);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (std::shared_ptr<cdk::compiler> compiler)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* file: %empty  */
#line 84 "mml_parser.y"
                                {compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE)); }
#line 1371 "mml_parser.tab.c"
    break;

  case 3: /* file: declarations  */
#line 85 "mml_parser.y"
                                {compiler->ast((yyvsp[0].sequence)); }
#line 1377 "mml_parser.tab.c"
    break;

  case 4: /* file: declarations program  */
#line 86 "mml_parser.y"
                                {compiler->ast((yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence))); }
#line 1383 "mml_parser.tab.c"
    break;

  case 5: /* file: program  */
#line 87 "mml_parser.y"
                                {compiler->ast((yyvsp[0].node)); }
#line 1389 "mml_parser.tab.c"
    break;

  case 6: /* declarations: declaration  */
#line 90 "mml_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1395 "mml_parser.tab.c"
    break;

  case 7: /* declarations: declarations declaration  */
#line 91 "mml_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1401 "mml_parser.tab.c"
    break;

  case 8: /* declaration: var_decl ';'  */
#line 93 "mml_parser.y"
                                           { (yyval.node) = (yyvsp[-1].node); }
#line 1407 "mml_parser.tab.c"
    break;

  case 9: /* declaration: var_decl  */
#line 94 "mml_parser.y"
                                           { (yyval.node) = (yyvsp[0].node); }
#line 1413 "mml_parser.tab.c"
    break;

  case 10: /* program: tBEGIN inner_block tEND  */
#line 102 "mml_parser.y"
                                  { compiler->ast(new mml::program_node(LINE, (yyvsp[-1].block))); }
#line 1419 "mml_parser.tab.c"
    break;

  case 11: /* function: '(' vars ')' tTYPE_RETURN data_type block  */
#line 105 "mml_parser.y"
                                                       { (yyval.expression) = new mml::function_definition_node(LINE, (yyvsp[-1].type), (yyvsp[-4].sequence), (yyvsp[0].block)); }
#line 1425 "mml_parser.tab.c"
    break;

  case 12: /* function: '(' ')' tTYPE_RETURN data_type block  */
#line 106 "mml_parser.y"
                                                       { (yyval.expression) = new mml::function_definition_node(LINE, (yyvsp[-1].type), new cdk::sequence_node(LINE), (yyvsp[0].block)); }
#line 1431 "mml_parser.tab.c"
    break;

  case 13: /* func_call: lval '(' exprs ')'  */
#line 109 "mml_parser.y"
                                          { (yyval.expression) = new mml::function_call_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-3].lvalue)), (yyvsp[-1].sequence)); }
#line 1437 "mml_parser.tab.c"
    break;

  case 14: /* func_call: lval '(' ')'  */
#line 110 "mml_parser.y"
                                          { (yyval.expression) = new mml::function_call_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-2].lvalue))); }
#line 1443 "mml_parser.tab.c"
    break;

  case 15: /* func_call: '@' '(' exprs ')'  */
#line 111 "mml_parser.y"
                                          { (yyval.expression) = new mml::function_call_node(LINE, nullptr, (yyvsp[-1].sequence)); }
#line 1449 "mml_parser.tab.c"
    break;

  case 16: /* func_call: '@' '(' ')'  */
#line 112 "mml_parser.y"
                                          { (yyval.expression) = new mml::function_call_node(LINE, nullptr); }
#line 1455 "mml_parser.tab.c"
    break;

  case 17: /* func_call: '(' expr ')' '(' exprs ')'  */
#line 113 "mml_parser.y"
                                          { (yyval.expression) = new mml::function_call_node(LINE, (yyvsp[-4].expression), (yyvsp[-1].sequence)); }
#line 1461 "mml_parser.tab.c"
    break;

  case 18: /* func_call: '(' expr ')' '(' ')'  */
#line 114 "mml_parser.y"
                                          { (yyval.expression) = new mml::function_call_node(LINE, (yyvsp[-3].expression)); }
#line 1467 "mml_parser.tab.c"
    break;

  case 19: /* block: '{' inner_block '}'  */
#line 122 "mml_parser.y"
                                         { (yyval.block) = (yyvsp[-1].block); }
#line 1473 "mml_parser.tab.c"
    break;

  case 20: /* inner_block: opt_var_decls opt_instrs  */
#line 125 "mml_parser.y"
                                          { (yyval.block) = new mml::block_node(LINE, (yyvsp[-1].sequence), (yyvsp[0].sequence)); }
#line 1479 "mml_parser.tab.c"
    break;

  case 21: /* opt_var_decls: %empty  */
#line 128 "mml_parser.y"
                                          { (yyval.sequence) = NULL; }
#line 1485 "mml_parser.tab.c"
    break;

  case 22: /* opt_var_decls: var_decls  */
#line 129 "mml_parser.y"
                                          { (yyval.sequence) = (yyvsp[0].sequence); }
#line 1491 "mml_parser.tab.c"
    break;

  case 23: /* opt_instrs: %empty  */
#line 132 "mml_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE); }
#line 1497 "mml_parser.tab.c"
    break;

  case 24: /* opt_instrs: opt_instrs instr  */
#line 133 "mml_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-1].sequence)); }
#line 1503 "mml_parser.tab.c"
    break;

  case 25: /* data_types: %empty  */
#line 141 "mml_parser.y"
                                             { (yyval.functype) = new std::vector<std::shared_ptr<cdk::basic_type>>();}
#line 1509 "mml_parser.tab.c"
    break;

  case 26: /* data_types: data_type  */
#line 142 "mml_parser.y"
                                             { (yyval.functype) = new std::vector<std::shared_ptr<cdk::basic_type>>(); (yyval.functype)->insert((yyval.functype)->begin(), (yyvsp[0].type));}
#line 1515 "mml_parser.tab.c"
    break;

  case 27: /* data_types: data_type ',' data_types  */
#line 143 "mml_parser.y"
                                             { (yyval.functype) = (yyvsp[0].functype); (yyval.functype)->insert((yyval.functype)->begin(), (yyvsp[-2].type)); }
#line 1521 "mml_parser.tab.c"
    break;

  case 28: /* data_type: tTYPE_STRING  */
#line 146 "mml_parser.y"
                                             { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_STRING); }
#line 1527 "mml_parser.tab.c"
    break;

  case 29: /* data_type: tTYPE_INT  */
#line 147 "mml_parser.y"
                                             { (yyval.type) = cdk::primitive_type::create(4, cdk::TYPE_INT); }
#line 1533 "mml_parser.tab.c"
    break;

  case 30: /* data_type: tTYPE_DOUBLE  */
#line 148 "mml_parser.y"
                                             { (yyval.type) = cdk::primitive_type::create(8, cdk::TYPE_DOUBLE); }
#line 1539 "mml_parser.tab.c"
    break;

  case 31: /* data_type: '[' data_type ']'  */
#line 149 "mml_parser.y"
                                             { (yyval.type) = cdk::reference_type::create(4, (yyvsp[-1].type)); }
#line 1545 "mml_parser.tab.c"
    break;

  case 32: /* data_type: func_type  */
#line 150 "mml_parser.y"
                                             { (yyval.type) = (yyvsp[0].type); }
#line 1551 "mml_parser.tab.c"
    break;

  case 33: /* func_type: return_type '<' data_types '>'  */
#line 153 "mml_parser.y"
                                             { (yyval.type) = cdk::functional_type::create(*(yyvsp[-1].functype), (yyvsp[-3].type));}
#line 1557 "mml_parser.tab.c"
    break;

  case 34: /* return_type: data_type  */
#line 156 "mml_parser.y"
                                              { (yyval.type) = (yyvsp[0].type); }
#line 1563 "mml_parser.tab.c"
    break;

  case 35: /* return_type: tTYPE_VOID  */
#line 157 "mml_parser.y"
                                              { (yyval.type) = cdk::primitive_type::create(0, cdk::TYPE_VOID); }
#line 1569 "mml_parser.tab.c"
    break;

  case 36: /* string: tSTRING  */
#line 160 "mml_parser.y"
                                              { (yyval.s) = (yyvsp[0].s); }
#line 1575 "mml_parser.tab.c"
    break;

  case 37: /* string: string tSTRING  */
#line 161 "mml_parser.y"
                                              { (yyval.s) = new std::string(*(yyvsp[-1].s) + *(yyvsp[0].s)); delete (yyvsp[-1].s); delete (yyvsp[0].s); }
#line 1581 "mml_parser.tab.c"
    break;

  case 38: /* vars: var  */
#line 169 "mml_parser.y"
                                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1587 "mml_parser.tab.c"
    break;

  case 39: /* vars: vars ',' var  */
#line 170 "mml_parser.y"
                                             { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].node), (yyvsp[-2].sequence)); }
#line 1593 "mml_parser.tab.c"
    break;

  case 40: /* var: data_type tIDENTIFIER  */
#line 173 "mml_parser.y"
                                             { (yyval.node) = new mml::variable_declaration_node(LINE, tDECL_PRIVATE, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1599 "mml_parser.tab.c"
    break;

  case 41: /* instr: expr  */
#line 181 "mml_parser.y"
                                         { (yyval.node) = new mml::evaluation_node(LINE, (yyvsp[0].expression)); }
#line 1605 "mml_parser.tab.c"
    break;

  case 42: /* instr: instr_cond  */
#line 182 "mml_parser.y"
                                   { (yyval.node) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1611 "mml_parser.tab.c"
    break;

  case 43: /* instr: instr_iter  */
#line 183 "mml_parser.y"
                                   { (yyval.node) = new cdk::sequence_node(LINE, (yyvsp[0].node)); }
#line 1617 "mml_parser.tab.c"
    break;

  case 44: /* instr: exprs tPRINT  */
#line 184 "mml_parser.y"
                                        { (yyval.node) = new mml::print_node(LINE, (yyvsp[-1].sequence), false); }
#line 1623 "mml_parser.tab.c"
    break;

  case 45: /* instr: exprs tPRINT_LN  */
#line 185 "mml_parser.y"
                                        { (yyval.node) = new mml::print_node(LINE, (yyvsp[-1].sequence), true); }
#line 1629 "mml_parser.tab.c"
    break;

  case 46: /* instr: tSTOP ';'  */
#line 186 "mml_parser.y"
                                         { (yyval.node) = new mml::stop_node(LINE); }
#line 1635 "mml_parser.tab.c"
    break;

  case 47: /* instr: tSTOP tINTEGER ';'  */
#line 187 "mml_parser.y"
                                         { (yyval.node) = new mml::stop_node(LINE, (yyvsp[-1].i)); }
#line 1641 "mml_parser.tab.c"
    break;

  case 48: /* instr: tNEXT ';'  */
#line 188 "mml_parser.y"
                                         { (yyval.node) = new mml::next_node(LINE); }
#line 1647 "mml_parser.tab.c"
    break;

  case 49: /* instr: tNEXT tINTEGER ';'  */
#line 189 "mml_parser.y"
                                         { (yyval.node) = new mml::next_node(LINE, (yyvsp[-1].i)); }
#line 1653 "mml_parser.tab.c"
    break;

  case 50: /* instr: tRETURN ';'  */
#line 190 "mml_parser.y"
                                         { (yyval.node) = new mml::return_node(LINE, nullptr); }
#line 1659 "mml_parser.tab.c"
    break;

  case 51: /* instr: tRETURN expr ';'  */
#line 191 "mml_parser.y"
                                         { (yyval.node) = new mml::return_node(LINE, (yyvsp[-1].expression)); }
#line 1665 "mml_parser.tab.c"
    break;

  case 52: /* instr: block  */
#line 192 "mml_parser.y"
                                         { (yyval.node) = (yyvsp[0].block); }
#line 1671 "mml_parser.tab.c"
    break;

  case 53: /* instr_cond: tIF '(' expr ')' instr  */
#line 195 "mml_parser.y"
                                                  { (yyval.node) = new mml::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1677 "mml_parser.tab.c"
    break;

  case 54: /* instr_cond: tIF '(' expr ')' instr false_cond  */
#line 196 "mml_parser.y"
                                                  { (yyval.node) = new mml::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1683 "mml_parser.tab.c"
    break;

  case 55: /* instr_iter: tWHILE '(' expr ')' instr  */
#line 199 "mml_parser.y"
                                                  { (yyval.node) = new mml::while_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1689 "mml_parser.tab.c"
    break;

  case 56: /* false_cond: tELSE instr  */
#line 202 "mml_parser.y"
                                                  { (yyval.node) = (yyvsp[0].node); }
#line 1695 "mml_parser.tab.c"
    break;

  case 57: /* false_cond: tELIF '(' expr ')' instr  */
#line 203 "mml_parser.y"
                                                  { (yyval.node) = new mml::if_node(LINE, (yyvsp[-2].expression), (yyvsp[0].node)); }
#line 1701 "mml_parser.tab.c"
    break;

  case 58: /* false_cond: tELIF '(' expr ')' instr false_cond  */
#line 204 "mml_parser.y"
                                                  { (yyval.node) = new mml::if_else_node(LINE, (yyvsp[-3].expression), (yyvsp[-1].node), (yyvsp[0].node)); }
#line 1707 "mml_parser.tab.c"
    break;

  case 59: /* opt_init: %empty  */
#line 212 "mml_parser.y"
                                      { (yyval.expression) = nullptr; }
#line 1713 "mml_parser.tab.c"
    break;

  case 60: /* opt_init: '=' expr  */
#line 213 "mml_parser.y"
                                      { (yyval.expression) = (yyvsp[0].expression); }
#line 1719 "mml_parser.tab.c"
    break;

  case 61: /* var_decls: var_decl ';'  */
#line 216 "mml_parser.y"
                                          { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node)); }
#line 1725 "mml_parser.tab.c"
    break;

  case 62: /* var_decls: var_decls var_decl ';'  */
#line 217 "mml_parser.y"
                                        { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[-1].node), (yyvsp[-2].sequence)); }
#line 1731 "mml_parser.tab.c"
    break;

  case 63: /* var_decl: tDECL_FORWARD data_type tIDENTIFIER  */
#line 220 "mml_parser.y"
                                                          { (yyval.node) = new mml::variable_declaration_node(LINE, tDECL_PUBLIC, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1737 "mml_parser.tab.c"
    break;

  case 64: /* var_decl: data_type tIDENTIFIER opt_init  */
#line 221 "mml_parser.y"
                                                          { (yyval.node) = new mml::variable_declaration_node(LINE, tDECL_PRIVATE, (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1743 "mml_parser.tab.c"
    break;

  case 65: /* var_decl: tDECL_PUBLIC data_type tIDENTIFIER opt_init  */
#line 222 "mml_parser.y"
                                                          { (yyval.node) = new mml::variable_declaration_node(LINE, tDECL_PUBLIC, (yyvsp[-2].type), *(yyvsp[-1].s), (yyvsp[0].expression)); }
#line 1749 "mml_parser.tab.c"
    break;

  case 66: /* var_decl: tDECL_PUBLIC tDECL_AUTO tIDENTIFIER '=' expr  */
#line 223 "mml_parser.y"
                                                          { (yyval.node) = new mml::variable_declaration_node(LINE, tDECL_PUBLIC, nullptr, *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1755 "mml_parser.tab.c"
    break;

  case 67: /* var_decl: tDECL_AUTO tIDENTIFIER '=' expr  */
#line 224 "mml_parser.y"
                                                          { (yyval.node) = new mml::variable_declaration_node(LINE, tDECL_PUBLIC, nullptr, *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1761 "mml_parser.tab.c"
    break;

  case 68: /* var_decl: tDECL_PUBLIC tIDENTIFIER '=' expr  */
#line 225 "mml_parser.y"
                                                          { (yyval.node) = new mml::variable_declaration_node(LINE, tDECL_PUBLIC, nullptr, *(yyvsp[-2].s), (yyvsp[0].expression)); }
#line 1767 "mml_parser.tab.c"
    break;

  case 69: /* var_decl: tDECL_FOREIGN data_type tIDENTIFIER  */
#line 226 "mml_parser.y"
                                                          { (yyval.node) = new mml::variable_declaration_node(LINE, tDECL_FOREIGN, (yyvsp[-1].type), *(yyvsp[0].s), nullptr); }
#line 1773 "mml_parser.tab.c"
    break;

  case 70: /* expr: tINTEGER  */
#line 235 "mml_parser.y"
                                 { (yyval.expression) = new cdk::integer_node(LINE, (yyvsp[0].i)); }
#line 1779 "mml_parser.tab.c"
    break;

  case 71: /* expr: tREAL  */
#line 236 "mml_parser.y"
                                 { (yyval.expression) = new cdk::double_node(LINE, (yyvsp[0].d)); }
#line 1785 "mml_parser.tab.c"
    break;

  case 72: /* expr: string  */
#line 237 "mml_parser.y"
                                 { (yyval.expression) = new cdk::string_node(LINE, (yyvsp[0].s)); }
#line 1791 "mml_parser.tab.c"
    break;

  case 73: /* expr: tNULLPTR  */
#line 238 "mml_parser.y"
                                 { (yyval.expression) = new mml::null_pointer_node(LINE); }
#line 1797 "mml_parser.tab.c"
    break;

  case 74: /* expr: lval  */
#line 239 "mml_parser.y"
                                 { (yyval.expression) = new cdk::rvalue_node(LINE, (yyvsp[0].lvalue)); }
#line 1803 "mml_parser.tab.c"
    break;

  case 75: /* expr: lval '=' expr  */
#line 240 "mml_parser.y"
                                 { (yyval.expression) = new cdk::assignment_node(LINE, (yyvsp[-2].lvalue), (yyvsp[0].expression)); }
#line 1809 "mml_parser.tab.c"
    break;

  case 76: /* expr: lval '?'  */
#line 241 "mml_parser.y"
                               { (yyval.expression) = new mml::address_of_node(LINE, (yyvsp[-1].lvalue)); }
#line 1815 "mml_parser.tab.c"
    break;

  case 77: /* expr: expr '+' expr  */
#line 242 "mml_parser.y"
                                 { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1821 "mml_parser.tab.c"
    break;

  case 78: /* expr: expr '-' expr  */
#line 243 "mml_parser.y"
                                 { (yyval.expression) = new cdk::sub_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1827 "mml_parser.tab.c"
    break;

  case 79: /* expr: expr '*' expr  */
#line 244 "mml_parser.y"
                                 { (yyval.expression) = new cdk::mul_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1833 "mml_parser.tab.c"
    break;

  case 80: /* expr: expr '/' expr  */
#line 245 "mml_parser.y"
                                 { (yyval.expression) = new cdk::div_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1839 "mml_parser.tab.c"
    break;

  case 81: /* expr: expr '%' expr  */
#line 246 "mml_parser.y"
                                 { (yyval.expression) = new cdk::mod_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1845 "mml_parser.tab.c"
    break;

  case 82: /* expr: expr '<' expr  */
#line 247 "mml_parser.y"
                                 { (yyval.expression) = new cdk::lt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1851 "mml_parser.tab.c"
    break;

  case 83: /* expr: expr '>' expr  */
#line 248 "mml_parser.y"
                                 { (yyval.expression) = new cdk::gt_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1857 "mml_parser.tab.c"
    break;

  case 84: /* expr: expr tGE expr  */
#line 249 "mml_parser.y"
                                 { (yyval.expression) = new cdk::ge_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1863 "mml_parser.tab.c"
    break;

  case 85: /* expr: expr tLE expr  */
#line 250 "mml_parser.y"
                                 { (yyval.expression) = new cdk::le_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1869 "mml_parser.tab.c"
    break;

  case 86: /* expr: expr tNE expr  */
#line 251 "mml_parser.y"
                                 { (yyval.expression) = new cdk::ne_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1875 "mml_parser.tab.c"
    break;

  case 87: /* expr: expr tEQ expr  */
#line 252 "mml_parser.y"
                                 { (yyval.expression) = new cdk::eq_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1881 "mml_parser.tab.c"
    break;

  case 88: /* expr: expr tAND expr  */
#line 253 "mml_parser.y"
                               { (yyval.expression) = new cdk::add_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1887 "mml_parser.tab.c"
    break;

  case 89: /* expr: expr tOR expr  */
#line 254 "mml_parser.y"
                               { (yyval.expression) = new cdk::or_node(LINE, (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1893 "mml_parser.tab.c"
    break;

  case 90: /* expr: '-' expr  */
#line 255 "mml_parser.y"
                                 { (yyval.expression) = new cdk::neg_node(LINE, (yyvsp[0].expression)); }
#line 1899 "mml_parser.tab.c"
    break;

  case 91: /* expr: '+' expr  */
#line 256 "mml_parser.y"
                                 { (yyval.expression) = new mml::identity_node(LINE, (yyvsp[0].expression)); }
#line 1905 "mml_parser.tab.c"
    break;

  case 92: /* expr: tNOT expr  */
#line 257 "mml_parser.y"
                               { (yyval.expression) = new cdk::not_node(LINE, (yyvsp[0].expression)); }
#line 1911 "mml_parser.tab.c"
    break;

  case 93: /* expr: tINPUT  */
#line 258 "mml_parser.y"
                               { (yyval.expression) = new mml::input_node(LINE); }
#line 1917 "mml_parser.tab.c"
    break;

  case 94: /* expr: tSIZEOF '(' expr ')'  */
#line 259 "mml_parser.y"
                               { (yyval.expression) = new mml::sizeof_node(LINE, (yyvsp[-1].expression)); }
#line 1923 "mml_parser.tab.c"
    break;

  case 95: /* expr: '(' expr ')'  */
#line 260 "mml_parser.y"
                               { (yyval.expression) = (yyvsp[-1].expression); }
#line 1929 "mml_parser.tab.c"
    break;

  case 96: /* expr: '[' expr ']'  */
#line 261 "mml_parser.y"
                               { (yyval.expression) = new mml::stack_alloc_node(LINE, (yyvsp[-1].expression)); }
#line 1935 "mml_parser.tab.c"
    break;

  case 97: /* expr: func_call  */
#line 262 "mml_parser.y"
                               { (yyval.expression) = (yyvsp[0].expression); }
#line 1941 "mml_parser.tab.c"
    break;

  case 98: /* expr: function  */
#line 263 "mml_parser.y"
                               { (yyval.expression) = (yyvsp[0].expression); }
#line 1947 "mml_parser.tab.c"
    break;

  case 99: /* exprs: expr  */
#line 266 "mml_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression)); }
#line 1953 "mml_parser.tab.c"
    break;

  case 100: /* exprs: exprs ',' expr  */
#line 267 "mml_parser.y"
                                   { (yyval.sequence) = new cdk::sequence_node(LINE, (yyvsp[0].expression), (yyvsp[-2].sequence)); }
#line 1959 "mml_parser.tab.c"
    break;

  case 101: /* lval: tIDENTIFIER  */
#line 274 "mml_parser.y"
                               { (yyval.lvalue) = new cdk::variable_node(LINE, (yyvsp[0].s)); }
#line 1965 "mml_parser.tab.c"
    break;

  case 102: /* lval: lval '[' expr ']'  */
#line 275 "mml_parser.y"
                                { (yyval.lvalue) = new mml::index_node(LINE, new cdk::rvalue_node(LINE, (yyvsp[-3].lvalue)), (yyvsp[-1].expression)); }
#line 1971 "mml_parser.tab.c"
    break;


#line 1975 "mml_parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (compiler, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, compiler);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, compiler);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (compiler, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, compiler);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, compiler);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 280 "mml_parser.y"

