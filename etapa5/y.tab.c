/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "hash.h"
#include "semantic.h"
#include "tacs.h"
#include "gencode.h"
int getLineNumber();
int yylex();
int yyerror();
FILE* outfile;

#line 84 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    KW_CHAR = 258,
    KW_INT = 259,
    KW_BOOL = 260,
    KW_POINTER = 261,
    KW_IF = 262,
    KW_THEN = 263,
    KW_ELSE = 264,
    KW_WHILE = 265,
    KW_READ = 266,
    KW_PRINT = 267,
    KW_RETURN = 268,
    OPERATOR_LE = 269,
    OPERATOR_GE = 270,
    OPERATOR_EQ = 271,
    OPERATOR_DIF = 272,
    LEFT_ASSIGN = 273,
    RIGHT_ASSIGN = 274,
    TK_IDENTIFIER = 275,
    LIT_INTEGER = 276,
    LIT_TRUE = 277,
    LIT_FALSE = 278,
    LIT_CHAR = 279,
    LIT_STRING = 280,
    TOKEN_ERROR = 281
  };
#endif
/* Tokens.  */
#define KW_CHAR 258
#define KW_INT 259
#define KW_BOOL 260
#define KW_POINTER 261
#define KW_IF 262
#define KW_THEN 263
#define KW_ELSE 264
#define KW_WHILE 265
#define KW_READ 266
#define KW_PRINT 267
#define KW_RETURN 268
#define OPERATOR_LE 269
#define OPERATOR_GE 270
#define OPERATOR_EQ 271
#define OPERATOR_DIF 272
#define LEFT_ASSIGN 273
#define RIGHT_ASSIGN 274
#define TK_IDENTIFIER 275
#define LIT_INTEGER 276
#define LIT_TRUE 277
#define LIT_FALSE 278
#define LIT_CHAR 279
#define LIT_STRING 280
#define TOKEN_ERROR 281

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "parser.y"

	node *symbol;
	ast *ast;

#line 193 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   343

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

#define YYUNDEFTOK  2
#define YYMAXUTOK   281


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    35,    36,     2,    28,     2,
      42,    43,    33,    31,    44,    32,     2,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    38,
      29,     2,    30,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,    27,    46,    37,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    88,    88,    97,    98,    99,   100,   104,   105,   106,
     110,   111,   112,   113,   118,   119,   124,   129,   130,   134,
     135,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     150,   151,   154,   155,   156,   157,   161,   162,   163,   164,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     189,   190,   193,   194,   198,   202,   205,   209,   210,   211,
     212
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_CHAR", "KW_INT", "KW_BOOL",
  "KW_POINTER", "KW_IF", "KW_THEN", "KW_ELSE", "KW_WHILE", "KW_READ",
  "KW_PRINT", "KW_RETURN", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_DIF", "LEFT_ASSIGN", "RIGHT_ASSIGN", "TK_IDENTIFIER",
  "LIT_INTEGER", "LIT_TRUE", "LIT_FALSE", "LIT_CHAR", "LIT_STRING",
  "TOKEN_ERROR", "'|'", "'&'", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'#'", "'$'", "'~'", "';'", "':'", "'['", "']'", "'('", "')'", "','",
  "'{'", "'}'", "$accept", "inicio", "programa", "decl", "type",
  "vector_value", "function", "parameters", "listparameters", "command",
  "block", "print", "assign", "expr", "func_arguments",
  "func_arguments_list", "identifier", "string", "int", "literals", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   124,    38,    60,
      62,    43,    45,    42,    47,    35,    36,   126,    59,    58,
      91,    93,    40,    41,    44,   123,   125
};
# endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-32)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,   -37,   -37,   -37,   -37,     5,   -37,   -20,   -13,    -9,
     -37,    67,   -37,    11,   -36,    67,   -37,   -37,     1,    89,
      67,   -37,    13,   -37,   -37,   -37,   -37,   -37,    13,    12,
     -37,    21,    17,    96,    89,    67,    20,    22,    13,   233,
     256,   256,   256,   256,   256,    56,   -37,   -37,   280,   -14,
     -37,   -37,    89,   -37,   256,   256,   -37,   -37,   -37,   120,
      -6,    30,   288,   -37,   -37,   -37,   151,    37,    36,   256,
     256,   256,   256,    13,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   -37,   159,   181,   233,   256,
     233,   -37,    56,   -37,    93,    93,    93,    93,    43,   309,
     309,    93,    93,   -12,   -12,   -37,   -37,   288,   189,   128,
      42,   -37,    78,    96,   -37,   211,   -37,   -37,   256,    70,
     256,   -37,    96,   -37,   -37,   232,   256,   -37,    85,   -37,
     288,    96,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,    12,    10,    13,     0,     2,     0,     0,     0,
       1,     5,    64,     0,     0,     6,     3,    66,     0,     0,
      18,     4,     0,    67,    68,    69,    70,     7,     0,     0,
      17,     9,    20,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29,    16,    24,     0,    41,
      43,     8,    15,    19,     0,     0,    22,    65,    25,    33,
      41,    32,    23,    47,    46,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    61,    14,     0,     0,     0,     0,
       0,    40,    29,    21,    56,    57,    58,    59,    38,    54,
      55,    52,    53,    48,    49,    50,    51,    36,     0,    63,
       0,    60,     0,    29,    35,     0,    34,    30,     0,    42,
       0,    44,    29,    28,    42,     0,     0,    62,    26,    39,
      37,    29,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,     4,   -37,    -4,    44,   -37,   -37,    62,   -32,
       8,   -34,   -37,   -31,   -37,   -16,    -8,   -37,   -37,   -17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    51,     9,    29,    30,    67,
      68,    58,    47,    48,   110,   111,    60,    61,    18,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    46,    27,    19,    82,    10,    20,    12,    59,    62,
      63,    64,    65,    66,    31,    16,    28,    52,    11,    21,
      32,    80,    81,    86,    87,    49,    83,    13,    84,    15,
      56,    28,    17,    12,    89,    52,    84,    49,    94,    95,
      96,    97,    22,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   114,    33,   116,    59,   115,    59,
      34,    35,    54,    36,    55,    98,    37,    38,    39,    40,
       1,     2,     3,     4,    90,    92,    12,    23,    24,    25,
      26,   123,    93,   118,    49,   121,   122,   125,   126,   109,
     128,    41,    42,    43,   131,   130,    85,    53,    44,   132,
     117,    45,   -31,    36,   127,    49,    37,    38,    39,    40,
      23,    24,    25,    26,    49,     0,    12,    23,    24,    25,
      26,     0,     0,    49,    78,    79,    80,    81,     0,     0,
       0,    41,    42,    43,    69,    70,    71,    72,    44,     0,
       0,    45,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    74,    75,    76,    77,    78,
      79,    80,    81,     0,    88,    69,    70,    71,    72,     0,
       0,     0,   120,    69,    70,    71,    72,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    74,    75,    76,    77,
      78,    79,    80,    81,    91,    69,    70,    71,    72,     0,
       0,     0,   112,    69,    70,    71,    72,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    74,    75,    76,    77,
      78,    79,    80,    81,   113,    69,    70,    71,    72,     0,
     119,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    69,    70,    71,    72,
       0,     0,   124,    12,    23,    24,    25,    26,    57,    74,
      75,    76,    77,    78,    79,    80,    81,     0,    41,    42,
      43,     0,     0,   129,     0,    44,    12,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,    42,    43,    69,    70,    71,    72,    44,    73,
       0,     0,    69,    70,    71,    72,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    74,    75,    76,    77,    78,
      79,    80,    81,    69,    70,    71,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
      78,    79,    80,    81
};

static const yytype_int16 yycheck[] =
{
       8,    33,    19,    39,    18,     0,    42,    20,    39,    40,
      41,    42,    43,    44,    22,    11,    20,    34,    38,    15,
      28,    33,    34,    54,    55,    33,    40,    40,    42,    38,
      38,    35,    21,    20,    40,    52,    42,    45,    69,    70,
      71,    72,    41,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    88,    43,    90,    88,    89,    90,
      39,    44,    42,     7,    42,    73,    10,    11,    12,    13,
       3,     4,     5,     6,    44,    38,    20,    21,    22,    23,
      24,   113,    46,    40,    92,    43,     8,   118,    18,   120,
     122,    35,    36,    37,     9,   126,    52,    35,    42,   131,
      92,    45,    46,     7,   120,   113,    10,    11,    12,    13,
      21,    22,    23,    24,   122,    -1,    20,    21,    22,    23,
      24,    -1,    -1,   131,    31,    32,    33,    34,    -1,    -1,
      -1,    35,    36,    37,    14,    15,    16,    17,    42,    -1,
      -1,    45,    14,    15,    16,    17,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    44,    14,    15,    16,    17,    -1,
      -1,    -1,    44,    14,    15,    16,    17,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    27,    28,    29,    30,
      31,    32,    33,    34,    43,    14,    15,    16,    17,    -1,
      -1,    -1,    43,    14,    15,    16,    17,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    27,    28,    29,    30,
      31,    32,    33,    34,    43,    14,    15,    16,    17,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    14,    15,    16,    17,
      -1,    -1,    41,    20,    21,    22,    23,    24,    25,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    35,    36,
      37,    -1,    -1,    41,    -1,    42,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    14,    15,    16,    17,    42,    19,
      -1,    -1,    14,    15,    16,    17,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    27,    28,    29,    30,    31,
      32,    33,    34,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    48,    49,    50,    51,    53,
       0,    38,    20,    40,    63,    38,    49,    21,    65,    39,
      42,    49,    41,    21,    22,    23,    24,    66,    51,    54,
      55,    63,    63,    43,    39,    44,     7,    10,    11,    12,
      13,    35,    36,    37,    42,    45,    56,    59,    60,    63,
      66,    52,    66,    55,    42,    42,    63,    25,    58,    60,
      63,    64,    60,    60,    60,    60,    60,    56,    57,    14,
      15,    16,    17,    19,    27,    28,    29,    30,    31,    32,
      33,    34,    18,    40,    42,    52,    60,    60,    44,    40,
      44,    43,    38,    46,    60,    60,    60,    60,    63,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    62,    43,    43,    58,    60,    58,    57,    40,    41,
      44,    43,     8,    56,    41,    60,    18,    62,    56,    41,
      60,     9,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    50,    50,    50,
      51,    51,    51,    51,    52,    52,    53,    54,    54,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    58,    58,    59,    59,    59,    59,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      61,    61,    62,    62,    63,    64,    65,    66,    66,    66,
      66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     3,     2,     2,     4,     7,     5,
       1,     1,     1,     1,     2,     1,     6,     1,     0,     4,
       2,     3,     2,     2,     1,     2,     6,     8,     5,     0,
       3,     0,     1,     1,     3,     3,     3,     6,     3,     6,
       3,     1,     4,     1,     4,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 88 "parser.y"
                 {check_and_set_declarations((yyvsp[0].ast));
check_undeclared();
check_types((yyvsp[0].ast));
astMakeCode((yyvsp[0].ast),outfile);
/*astPrint($1,0);*/
tacPrintReverse(genCode((yyvsp[0].ast)));
}
#line 1507 "y.tab.c"
    break;

  case 3:
#line 97 "parser.y"
                           {(yyval.ast) = astGenerate(AST_LST_DECL,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1513 "y.tab.c"
    break;

  case 4:
#line 98 "parser.y"
                                {(yyval.ast) = astGenerate(AST_LST_FUNC,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1519 "y.tab.c"
    break;

  case 5:
#line 99 "parser.y"
                   {(yyval.ast) = astGenerate(AST_LSTEND_DECL,0,(yyvsp[-1].ast),0,0,0);}
#line 1525 "y.tab.c"
    break;

  case 6:
#line 100 "parser.y"
                       {(yyval.ast) = astGenerate(AST_LSTEND_FUNC,0,(yyvsp[-1].ast),0,0,0);}
#line 1531 "y.tab.c"
    break;

  case 7:
#line 104 "parser.y"
                                     {(yyval.ast) = astGenerate(AST_DECL_LIT,0,(yyvsp[-3].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0);}
#line 1537 "y.tab.c"
    break;

  case 8:
#line 105 "parser.y"
                                                        {(yyval.ast) = astGenerate(AST_DECL_VEC,0,(yyvsp[-6].ast),(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1543 "y.tab.c"
    break;

  case 9:
#line 106 "parser.y"
                                     {(yyval.ast) = astGenerate(AST_DECL_VEC_EMPTY,0,(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0);}
#line 1549 "y.tab.c"
    break;

  case 10:
#line 110 "parser.y"
                {(yyval.ast) = astGenerate(AST_KW_BOOL,0,0,0,0,0);}
#line 1555 "y.tab.c"
    break;

  case 11:
#line 111 "parser.y"
                 {(yyval.ast) = astGenerate(AST_KW_CHAR,0,0,0,0,0);}
#line 1561 "y.tab.c"
    break;

  case 12:
#line 112 "parser.y"
                 {(yyval.ast) = astGenerate(AST_KW_INT,0,0,0,0,0);}
#line 1567 "y.tab.c"
    break;

  case 13:
#line 113 "parser.y"
                    {(yyval.ast) = astGenerate(AST_KW_POINTER,0,0,0,0,0);}
#line 1573 "y.tab.c"
    break;

  case 14:
#line 118 "parser.y"
                              {(yyval.ast) = astGenerate(AST_LST_VEC1,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0);}
#line 1579 "y.tab.c"
    break;

  case 15:
#line 119 "parser.y"
                   {(yyval.ast) = astGenerate(AST_LST_VEC2,0,(yyvsp[0].ast),0,0,0);}
#line 1585 "y.tab.c"
    break;

  case 16:
#line 124 "parser.y"
                                                   {(yyval.ast) = astGenerate(AST_FUNCTION,0,(yyvsp[-5].ast),(yyvsp[-4].ast),(yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1591 "y.tab.c"
    break;

  case 17:
#line 129 "parser.y"
                       {(yyval.ast) = (yyvsp[0].ast);}
#line 1597 "y.tab.c"
    break;

  case 18:
#line 130 "parser.y"
          {(yyval.ast) = 0;}
#line 1603 "y.tab.c"
    break;

  case 19:
#line 134 "parser.y"
                                           {(yyval.ast) = astGenerate(AST_LST_PAR,0,(yyvsp[-3].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0);}
#line 1609 "y.tab.c"
    break;

  case 20:
#line 135 "parser.y"
                          {(yyval.ast) = astGenerate(AST_LST_PAREND,0,(yyvsp[-1].ast),(yyvsp[0].ast),0,0);}
#line 1615 "y.tab.c"
    break;

  case 21:
#line 138 "parser.y"
                      { (yyval.ast) = astGenerate(AST_BLOCK,0,(yyvsp[-1].ast),0,0,0);}
#line 1621 "y.tab.c"
    break;

  case 22:
#line 139 "parser.y"
                             { (yyval.ast) = astGenerate(AST_READ,0,(yyvsp[0].ast),0,0,0);}
#line 1627 "y.tab.c"
    break;

  case 23:
#line 140 "parser.y"
                         { (yyval.ast) = astGenerate(AST_RETURN,0,(yyvsp[0].ast),0,0,0);}
#line 1633 "y.tab.c"
    break;

  case 24:
#line 141 "parser.y"
                 {(yyval.ast) = (yyvsp[0].ast);}
#line 1639 "y.tab.c"
    break;

  case 25:
#line 142 "parser.y"
                         { (yyval.ast) = astGenerate(AST_PRINT,0,(yyvsp[0].ast),0,0,0);}
#line 1645 "y.tab.c"
    break;

  case 26:
#line 143 "parser.y"
                                             { (yyval.ast) = astGenerate(AST_IF,0,(yyvsp[-3].ast),(yyvsp[0].ast),0,0);}
#line 1651 "y.tab.c"
    break;

  case 27:
#line 144 "parser.y"
                                                             { (yyval.ast) = astGenerate(AST_IFELSE,0,(yyvsp[-5].ast),(yyvsp[-2].ast),(yyvsp[0].ast),0);}
#line 1657 "y.tab.c"
    break;

  case 28:
#line 145 "parser.y"
                                         {(yyval.ast) = astGenerate(AST_WHILE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1663 "y.tab.c"
    break;

  case 29:
#line 146 "parser.y"
          {(yyval.ast) = 0;}
#line 1669 "y.tab.c"
    break;

  case 30:
#line 150 "parser.y"
                          { (yyval.ast) = astGenerate(AST_BLOCKLST,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1675 "y.tab.c"
    break;

  case 31:
#line 151 "parser.y"
          {(yyval.ast) = 0;}
#line 1681 "y.tab.c"
    break;

  case 32:
#line 154 "parser.y"
              { (yyval.ast) = (yyvsp[0].ast);}
#line 1687 "y.tab.c"
    break;

  case 33:
#line 155 "parser.y"
               { (yyval.ast) = (yyvsp[0].ast);}
#line 1693 "y.tab.c"
    break;

  case 34:
#line 156 "parser.y"
                           { (yyval.ast) = astGenerate(AST_PRINTLST_STRING,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1699 "y.tab.c"
    break;

  case 35:
#line 157 "parser.y"
                         { (yyval.ast) = astGenerate(AST_PRINTLST_EXPR,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1705 "y.tab.c"
    break;

  case 36:
#line 161 "parser.y"
                                    { (yyval.ast) = astGenerate(AST_LEFT_ASSIGN,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1711 "y.tab.c"
    break;

  case 37:
#line 162 "parser.y"
                                                   { (yyval.ast) = astGenerate(AST_LEFT_ASSIGN_VEC,0,(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[0].ast),0);}
#line 1717 "y.tab.c"
    break;

  case 38:
#line 163 "parser.y"
                                       { (yyval.ast) = astGenerate(AST_RIGHT_ASSIGN,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1723 "y.tab.c"
    break;

  case 39:
#line 164 "parser.y"
                                                    { (yyval.ast) = astGenerate(AST_RIGHT_ASSIGN_VEC,0,(yyvsp[-5].ast),(yyvsp[-3].ast),(yyvsp[-1].ast),0);}
#line 1729 "y.tab.c"
    break;

  case 40:
#line 167 "parser.y"
                     { (yyval.ast) = astGenerate(AST_PARENTESIS,0,(yyvsp[-1].ast),0,0,0);}
#line 1735 "y.tab.c"
    break;

  case 41:
#line 168 "parser.y"
                     { (yyval.ast) = (yyvsp[0].ast);}
#line 1741 "y.tab.c"
    break;

  case 42:
#line 169 "parser.y"
                                  { (yyval.ast) = astGenerate(AST_VECTOR,0,(yyvsp[-3].ast),(yyvsp[-1].ast),0,0);}
#line 1747 "y.tab.c"
    break;

  case 43:
#line 170 "parser.y"
                   {(yyval.ast) = (yyvsp[0].ast);}
#line 1753 "y.tab.c"
    break;

  case 44:
#line 171 "parser.y"
                                            { (yyval.ast) = astGenerate(AST_EXPR_FUNCTION,0,(yyvsp[-3].ast),(yyvsp[-1].ast),0,0);}
#line 1759 "y.tab.c"
    break;

  case 45:
#line 172 "parser.y"
                   { (yyval.ast) = astGenerate(AST_NEG,0,(yyvsp[0].ast),0,0,0);}
#line 1765 "y.tab.c"
    break;

  case 46:
#line 173 "parser.y"
                   { (yyval.ast) = astGenerate(AST_DOLLAR,0,(yyvsp[0].ast),0,0,0);}
#line 1771 "y.tab.c"
    break;

  case 47:
#line 174 "parser.y"
                   { (yyval.ast) = astGenerate(AST_HASHTAG,0,(yyvsp[0].ast),0,0,0);}
#line 1777 "y.tab.c"
    break;

  case 48:
#line 175 "parser.y"
                        {(yyval.ast) = astGenerate(AST_ADD,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1783 "y.tab.c"
    break;

  case 49:
#line 176 "parser.y"
                        {(yyval.ast) = astGenerate(AST_SUB,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1789 "y.tab.c"
    break;

  case 50:
#line 177 "parser.y"
                        {(yyval.ast) = astGenerate(AST_MULT,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1795 "y.tab.c"
    break;

  case 51:
#line 178 "parser.y"
                        {(yyval.ast) = astGenerate(AST_DIV,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1801 "y.tab.c"
    break;

  case 52:
#line 179 "parser.y"
                        {(yyval.ast) = astGenerate(AST_LESS,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1807 "y.tab.c"
    break;

  case 53:
#line 180 "parser.y"
                        {(yyval.ast) = astGenerate(AST_GREATER,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1813 "y.tab.c"
    break;

  case 54:
#line 181 "parser.y"
                       {(yyval.ast) = astGenerate(AST_OR,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1819 "y.tab.c"
    break;

  case 55:
#line 182 "parser.y"
                        {(yyval.ast) = astGenerate(AST_AND,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1825 "y.tab.c"
    break;

  case 56:
#line 183 "parser.y"
                                 {(yyval.ast) = astGenerate(AST_LE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1831 "y.tab.c"
    break;

  case 57:
#line 184 "parser.y"
                                  {(yyval.ast) = astGenerate(AST_GE,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1837 "y.tab.c"
    break;

  case 58:
#line 185 "parser.y"
                                  {(yyval.ast) = astGenerate(AST_EQ,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1843 "y.tab.c"
    break;

  case 59:
#line 186 "parser.y"
                                  {(yyval.ast) = astGenerate(AST_DIF,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1849 "y.tab.c"
    break;

  case 60:
#line 189 "parser.y"
                            {(yyval.ast) = (yyvsp[0].ast);}
#line 1855 "y.tab.c"
    break;

  case 61:
#line 190 "parser.y"
          {(yyval.ast) = 0;}
#line 1861 "y.tab.c"
    break;

  case 62:
#line 193 "parser.y"
                                     {(yyval.ast) = astGenerate(AST_FUNC_ARGUMENTS,0,(yyvsp[-2].ast),(yyvsp[0].ast),0,0);}
#line 1867 "y.tab.c"
    break;

  case 63:
#line 194 "parser.y"
               {(yyval.ast) = (yyvsp[0].ast);}
#line 1873 "y.tab.c"
    break;

  case 64:
#line 198 "parser.y"
                      {(yyval.ast) = astGenerate(AST_SYMBOL_IDENTIFIER,(yyvsp[0].symbol),0,0,0,0);}
#line 1879 "y.tab.c"
    break;

  case 65:
#line 202 "parser.y"
                  {(yyval.ast) = astGenerate(AST_SYMBOL_STRING,(yyvsp[0].symbol),0,0,0,0);}
#line 1885 "y.tab.c"
    break;

  case 66:
#line 205 "parser.y"
                   {(yyval.ast) = astGenerate(AST_SYMBOL_INT,(yyvsp[0].symbol),0,0,0,0);}
#line 1891 "y.tab.c"
    break;

  case 67:
#line 209 "parser.y"
                    {(yyval.ast) = astGenerate(AST_SYMBOL_INT,(yyvsp[0].symbol),0,0,0,0);}
#line 1897 "y.tab.c"
    break;

  case 68:
#line 210 "parser.y"
                   {(yyval.ast) = astGenerate(AST_SYMBOL_TRUE,(yyvsp[0].symbol),0,0,0,0); }
#line 1903 "y.tab.c"
    break;

  case 69:
#line 211 "parser.y"
                    {(yyval.ast) = astGenerate(AST_SYMBOL_FALSE,(yyvsp[0].symbol),0,0,0,0);}
#line 1909 "y.tab.c"
    break;

  case 70:
#line 212 "parser.y"
                   {(yyval.ast) = astGenerate(AST_SYMBOL_CHAR,(yyvsp[0].symbol),0,0,0,0); }
#line 1915 "y.tab.c"
    break;


#line 1919 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
                      yytoken, &yylval);
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 217 "parser.y"


int yyerror(){
	
	printf("Erro de sintaxe na linha %d\n",getLineNumber());
	exit(3);
}

void loadOutFile(FILE *saida){
	outfile = saida;
}
