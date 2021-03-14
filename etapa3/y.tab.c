/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "hash.h"
int getLineNumber();
int yylex();
FILE* outfile;
#line 11 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{
	node *symbol;
	ast *ast;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 41 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KW_CHAR 257
#define KW_INT 258
#define KW_BOOL 259
#define KW_POINTER 260
#define KW_IF 261
#define KW_THEN 262
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_READ 265
#define KW_PRINT 266
#define KW_RETURN 267
#define OPERATOR_LE 268
#define OPERATOR_GE 269
#define OPERATOR_EQ 270
#define OPERATOR_DIF 271
#define LEFT_ASSIGN 272
#define RIGHT_ASSIGN 273
#define TK_IDENTIFIER 274
#define LIT_INTEGER 275
#define LIT_TRUE 276
#define LIT_FALSE 277
#define LIT_CHAR 278
#define LIT_STRING 279
#define TOKEN_ERROR 280
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    9,    9,    9,    9,   10,   10,   10,   12,   12,
   12,   12,   13,   13,   11,   14,   14,   16,   16,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   17,   17,
   18,   18,   18,   18,    8,    8,    8,    8,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    2,    2,
    3,    3,    7,    5,    4,    6,    6,    6,    6,
};
static const YYINT yylen[] = {                            2,
    1,    3,    3,    2,    2,    4,    8,    5,    1,    1,
    1,    1,    2,    0,    6,    1,    0,    4,    2,    3,
    2,    2,    1,    2,    6,    8,    5,    0,    3,    0,
    1,    1,    3,    3,    3,    6,    3,    6,    3,    1,
    4,    1,    4,    2,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    1,    0,
    3,    1,    1,    1,    1,    1,    1,    1,    1,
};
static const YYINT yydefred[] = {                         0,
   10,   11,    9,   12,    0,    1,    0,    0,    0,    0,
    0,   63,    0,    0,    2,    3,   65,    0,    0,    0,
    0,   66,   67,   68,   69,    6,    0,    0,   16,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   42,    0,   23,   15,    0,
   18,    0,    0,   21,   64,    0,    0,    0,   24,    0,
   46,   45,   44,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    7,    0,    0,    0,    0,    0,   39,
    0,   20,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   49,   50,    0,    0,    0,    0,   59,
   13,    0,    0,   34,   33,    0,   29,    0,    0,    0,
   43,    0,   27,   41,    0,    0,   61,    0,   38,    0,
    0,   26,
};
static const YYINT yydgoto[] = {                          5,
   45,  109,  110,   18,   57,   46,   58,   48,    6,    7,
    8,    9,   84,   28,   65,   29,   66,   59,
};
static const YYINT yysindex[] = {                      -178,
    0,    0,    0,    0,    0,    0,  -27,   -8,  -82, -178,
 -178,    0, -253,  -37,    0,    0,    0,  -63, -118, -178,
 -235,    0,    0,    0,    0,    0, -235,   17,    0,  -17,
   18,  -29, -118, -178,   28,   32, -235,  -35,  -23,  -23,
  -23,  -23,  -23,  -29,  135,    0,  -14,    0,    0, -118,
    0,  -23,  -23,    0,    0,  353,   30,  -20,    0,  503,
    0,    0,    0,  378,   24,  -32,  -23,  -23,  -23,  -23,
 -235,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,  -23,
  -23,  -23, -118,    0,  386,  409,  -35,  -35,  -23,    0,
  -29,    0,  -18,  -18,  -18,  -18,   -3,  324,  324,  -18,
  -18,  -19,  -19,    0,    0,  503,  419,  444,   49,    0,
    0, -166,  -29,    0,    0,  454,    0,  -23, -170,  -23,
    0,  -29,    0,    0,  493,  -23,    0, -158,    0,  503,
  -29,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  108,
  112,    0,    0,    0,    0,    0,    0,    0,    0,   73,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   56,
   75,   60,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -55,    0,    0,  141,    0,    0,   61,
    0,    0,    0,    0,    0,  -57,  -51,   -7,    0,  -49,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   85,   61,    0,    0,    0,    0,    0,    0,    0,
  -55,    0,   25,   51,   63,   83,  -45,  264,  266,   92,
  109,    5,   16,    0,    0,  -44,    0,   90,    0,    0,
    0,    0,  -43,    0,    0,    0,    0,    0,  166,    0,
    0,  -43,    0,    0,    0,    0,    0,   76,    0,  -41,
  -43,    0,
};
static const YYINT yygindex[] = {                         0,
  664,    0,   14,    0,    0,   23,  540,    0,   34,    0,
    0,   -1,   55,    0,   15,   98,   48,   12,
};
#define YYTABLESIZE 790
static const YYINT yytable[] = {                         40,
   41,   32,   20,   28,   43,   40,   41,   31,   13,   22,
   43,   40,   41,   37,   35,   28,   43,   36,   27,   82,
   19,   17,   78,   78,   76,   82,   77,   79,   79,   21,
   40,   10,   27,   40,   40,   40,   40,   40,   12,   40,
   33,   26,   47,   15,   16,   47,   49,   47,   47,   47,
   11,   40,   40,   48,   40,   50,   48,   32,   48,   48,
   48,   34,   55,   47,   47,   55,   47,   52,   55,   30,
   89,   53,   83,   88,   48,   48,   81,   48,    1,    2,
    3,    4,   91,   55,   55,   40,   55,  118,   56,  121,
   42,   56,   92,   44,   56,  122,   42,   47,  114,  115,
   57,  126,   42,   57,  131,   83,   57,    4,   48,   56,
   56,    5,   56,   17,    8,   19,   40,   55,   28,   14,
   58,   57,   57,   58,   57,   60,   58,  123,   47,   51,
   62,   51,   51,  127,   25,   51,  128,  111,  117,   48,
    0,   58,   58,   56,   58,  132,   52,    0,   55,   52,
   51,   51,   52,   51,    0,   57,   22,   23,   24,   25,
    0,    0,    0,    0,    0,    0,    0,   52,   52,    0,
   52,    0,   73,    0,   56,   58,   78,   76,   40,   77,
    0,   79,   40,   40,   51,   40,   57,   40,    0,    0,
    0,   12,    0,    0,   74,    0,   75,    0,    0,    0,
   40,   52,   40,   41,    0,   32,   58,   41,   41,    0,
   41,   31,   41,   22,    0,   51,    0,   37,   35,   28,
    0,   36,    0,    0,    0,   41,    0,   41,    0,    0,
    0,   35,   52,    0,   36,   37,   38,   39,   12,   22,
   23,   24,   25,   55,   12,   22,   23,   24,   25,    0,
   12,   22,   23,   24,   25,   40,    0,   80,   72,    0,
   40,   40,   40,   40,   40,   40,    0,   47,    0,    0,
    0,    0,   47,   47,   47,   47,    0,   47,   48,    0,
    0,    0,    0,   48,   48,   48,   48,   55,   48,   41,
    0,    0,   55,   55,   55,   55,    0,   55,    0,    0,
    0,   53,    0,   54,   53,    0,   54,   53,    0,   54,
    0,    0,    0,   56,    0,    0,    0,    0,   56,   56,
   56,   56,   53,   56,   54,   57,    0,    0,    0,    0,
   57,   57,   57,   57,    0,   57,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   58,    0,    0,    0,    0,
   58,   58,   58,   58,   51,   58,   53,    0,   54,   51,
   51,   51,   51,    0,   51,   78,   76,    0,   77,    0,
   79,   52,    0,    0,    0,    0,   52,   52,   52,   52,
    0,   52,    0,   74,    0,   75,    0,   53,    0,   54,
   73,    0,    0,    0,   78,   76,   87,   77,    0,   79,
    0,    0,   67,   68,   69,   70,    0,   71,   40,   40,
   40,   40,   74,   40,   75,   73,    0,    0,   90,   78,
   76,    0,   77,   73,   79,    0,  112,   78,   76,    0,
   77,    0,   79,   41,   41,   41,   41,   74,   41,   75,
    0,    0,    0,    0,    0,   74,   73,   75,    0,  113,
   78,   76,    0,   77,    0,   79,   73,    0,    0,    0,
   78,   76,    0,   77,    0,   79,    0,    0,   74,    0,
   75,    0,    0,    0,    0,    0,   72,    0,   74,    0,
   75,   73,    0,    0,    0,   78,   76,  120,   77,    0,
   79,   73,    0,    0,    0,   78,   76,    0,   77,    0,
   79,   72,    0,   74,    0,   75,    0,    0,    0,   72,
    0,  119,    0,   74,    0,   75,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   53,    0,   54,    0,
   73,    0,   72,    0,   78,   76,   53,   77,   54,   79,
   73,    0,   72,    0,   78,   76,  124,   77,   14,   79,
    0,    0,   74,    0,   75,    0,    0,    0,    0,    0,
   30,    0,   74,    0,   75,    0,   31,   72,    0,    0,
    0,   47,    0,    0,    0,    0,   54,   72,    0,    0,
    0,    0,    0,   47,    0,  129,    0,    0,    0,    0,
    0,   67,   68,   69,   70,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   97,    0,    0,    0,    0,    0,   72,    0,    0,    0,
   67,   68,   69,   70,    0,    0,   72,    0,    0,    0,
   47,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   67,   68,   69,   70,    0,
    0,    0,   47,   67,   68,   69,   70,    0,    0,    0,
    0,   47,    0,    0,    0,    0,    0,    0,    0,    0,
   47,    0,    0,    0,    0,    0,   67,   68,   69,   70,
    0,    0,    0,    0,    0,    0,   67,   68,   69,   70,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   56,   60,   61,   62,   63,   64,    0,    0,    0,
    0,   67,   68,   69,   70,   85,   86,    0,    0,    0,
    0,   67,   68,   69,   70,    0,    0,    0,    0,    0,
   93,   94,   95,   96,    0,   98,   99,  100,  101,  102,
  103,  104,  105,  106,  107,  108,    0,    0,    0,    0,
   56,   56,  116,    0,    0,    0,    0,    0,    0,    0,
   67,   68,   69,   70,    0,    0,    0,    0,    0,    0,
   67,   68,   69,   70,    0,    0,    0,    0,    0,    0,
    0,  125,    0,  108,    0,    0,    0,    0,    0,  130,
};
static const YYINT yycheck[] = {                         35,
   36,   59,   40,   59,   40,   35,   36,   59,   91,   59,
   40,   35,   36,   59,   59,   59,   40,   59,   20,   40,
   58,  275,   42,   42,   43,   40,   45,   47,   47,   93,
   38,   59,   34,   41,   42,   43,   44,   45,  274,   47,
   58,   19,   38,   10,   11,   41,   32,   43,   44,   45,
   59,   59,   60,   38,   62,   33,   41,   41,   43,   44,
   45,   44,   38,   59,   60,   41,   62,   40,   44,  125,
   91,   40,   50,   44,   59,   60,   91,   62,  257,  258,
  259,  260,   59,   59,   60,   93,   62,   91,   38,   41,
  126,   41,  125,  123,   44,  262,  126,   93,   87,   88,
   38,  272,  126,   41,  263,   83,   44,    0,   93,   59,
   60,    0,   62,   41,   59,   41,  124,   93,   59,   59,
   38,   59,   60,   41,   62,   41,   44,  113,  124,   38,
   41,   34,   41,  120,   59,   44,  122,   83,   91,  124,
   -1,   59,   60,   93,   62,  131,   38,   -1,  124,   41,
   59,   60,   44,   62,   -1,   93,  275,  276,  277,  278,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,   -1,
   62,   -1,   38,   -1,  124,   93,   42,   43,   38,   45,
   -1,   47,   42,   43,   93,   45,  124,   47,   -1,   -1,
   -1,  274,   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,
   60,   93,   62,   38,   -1,  263,  124,   42,   43,   -1,
   45,  263,   47,  263,   -1,  124,   -1,  263,  263,  263,
   -1,  263,   -1,   -1,   -1,   60,   -1,   62,   -1,   -1,
   -1,  261,  124,   -1,  264,  265,  266,  267,  274,  275,
  276,  277,  278,  279,  274,  275,  276,  277,  278,   -1,
  274,  275,  276,  277,  278,  263,   -1,  272,  124,   -1,
  268,  269,  270,  271,  124,  273,   -1,  263,   -1,   -1,
   -1,   -1,  268,  269,  270,  271,   -1,  273,  263,   -1,
   -1,   -1,   -1,  268,  269,  270,  271,  263,  273,  124,
   -1,   -1,  268,  269,  270,  271,   -1,  273,   -1,   -1,
   -1,   38,   -1,   38,   41,   -1,   41,   44,   -1,   44,
   -1,   -1,   -1,  263,   -1,   -1,   -1,   -1,  268,  269,
  270,  271,   59,  273,   59,  263,   -1,   -1,   -1,   -1,
  268,  269,  270,  271,   -1,  273,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  263,   -1,   -1,   -1,   -1,
  268,  269,  270,  271,  263,  273,   93,   -1,   93,  268,
  269,  270,  271,   -1,  273,   42,   43,   -1,   45,   -1,
   47,  263,   -1,   -1,   -1,   -1,  268,  269,  270,  271,
   -1,  273,   -1,   60,   -1,   62,   -1,  124,   -1,  124,
   38,   -1,   -1,   -1,   42,   43,   44,   45,   -1,   47,
   -1,   -1,  268,  269,  270,  271,   -1,  273,  268,  269,
  270,  271,   60,  273,   62,   38,   -1,   -1,   41,   42,
   43,   -1,   45,   38,   47,   -1,   41,   42,   43,   -1,
   45,   -1,   47,  268,  269,  270,  271,   60,  273,   62,
   -1,   -1,   -1,   -1,   -1,   60,   38,   62,   -1,   41,
   42,   43,   -1,   45,   -1,   47,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   60,   -1,
   62,   -1,   -1,   -1,   -1,   -1,  124,   -1,   60,   -1,
   62,   38,   -1,   -1,   -1,   42,   43,   44,   45,   -1,
   47,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,  124,   -1,   60,   -1,   62,   -1,   -1,   -1,  124,
   -1,   93,   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,  263,   -1,
   38,   -1,  124,   -1,   42,   43,  273,   45,  273,   47,
   38,   -1,  124,   -1,   42,   43,   93,   45,    9,   47,
   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
   21,   -1,   60,   -1,   62,   -1,   27,  124,   -1,   -1,
   -1,   32,   -1,   -1,   -1,   -1,   37,  124,   -1,   -1,
   -1,   -1,   -1,   44,   -1,   93,   -1,   -1,   -1,   -1,
   -1,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   71,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
  268,  269,  270,  271,   -1,   -1,  124,   -1,   -1,   -1,
   91,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  268,  269,  270,  271,   -1,
   -1,   -1,  113,  268,  269,  270,  271,   -1,   -1,   -1,
   -1,  122,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  131,   -1,   -1,   -1,   -1,   -1,  268,  269,  270,  271,
   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,  270,  271,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   38,   39,   40,   41,   42,   43,   -1,   -1,   -1,
   -1,  268,  269,  270,  271,   52,   53,   -1,   -1,   -1,
   -1,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   67,   68,   69,   70,   -1,   72,   73,   74,   75,   76,
   77,   78,   79,   80,   81,   82,   -1,   -1,   -1,   -1,
   87,   88,   89,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,
  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  118,   -1,  120,   -1,   -1,   -1,   -1,   -1,  126,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 301
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'#'","'$'",0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,
0,0,0,0,"':'","';'","'<'",0,"'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_CHAR","KW_INT","KW_BOOL",
"KW_POINTER","KW_IF","KW_THEN","KW_ELSE","KW_WHILE","KW_READ","KW_PRINT",
"KW_RETURN","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_DIF",
"LEFT_ASSIGN","RIGHT_ASSIGN","TK_IDENTIFIER","LIT_INTEGER","LIT_TRUE",
"LIT_FALSE","LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : inicio",
"inicio : programa",
"programa : decl ';' programa",
"programa : function ';' programa",
"programa : decl ';'",
"programa : function ';'",
"decl : type identifier ':' literals",
"decl : type '[' int ']' identifier ':' literals vector_value",
"decl : type '[' int ']' identifier",
"type : KW_BOOL",
"type : KW_CHAR",
"type : KW_INT",
"type : KW_POINTER",
"vector_value : literals vector_value",
"vector_value :",
"function : type identifier '(' parameters ')' command",
"parameters : listparameters",
"parameters :",
"listparameters : type identifier ',' listparameters",
"listparameters : type identifier",
"command : '{' block '}'",
"command : KW_READ identifier",
"command : KW_RETURN expr",
"command : assign",
"command : KW_PRINT print",
"command : KW_IF '(' expr ')' KW_THEN command",
"command : KW_IF '(' expr ')' KW_THEN command KW_ELSE command",
"command : KW_WHILE '(' expr ')' command",
"command :",
"block : command ';' block",
"block :",
"print : string",
"print : expr",
"print : string ',' print",
"print : expr ',' print",
"assign : identifier LEFT_ASSIGN expr",
"assign : identifier '[' expr ']' LEFT_ASSIGN expr",
"assign : expr RIGHT_ASSIGN identifier",
"assign : expr RIGHT_ASSIGN identifier '[' expr ']'",
"expr : '(' expr ')'",
"expr : identifier",
"expr : identifier '[' expr ']'",
"expr : literals",
"expr : identifier '(' func_arguments ')'",
"expr : '~' expr",
"expr : '$' expr",
"expr : '#' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr '|' expr",
"expr : expr '&' expr",
"expr : expr OPERATOR_LE expr",
"expr : expr OPERATOR_GE expr",
"expr : expr OPERATOR_EQ expr",
"expr : expr OPERATOR_DIF expr",
"func_arguments : func_arguments_list",
"func_arguments :",
"func_arguments_list : expr ',' func_arguments_list",
"func_arguments_list : expr",
"identifier : TK_IDENTIFIER",
"string : LIT_STRING",
"int : LIT_INTEGER",
"literals : LIT_INTEGER",
"literals : LIT_TRUE",
"literals : LIT_FALSE",
"literals : LIT_CHAR",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 199 "parser.y"

int yyerror(){
	
	printf("Erro de sintaxe na linha %d\n",getLineNumber());
	exit(3);
}

void loadOutFile(FILE *saida){
	outfile = saida;
}
#line 480 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 23:
#line 122 "parser.y"
	{astPrint(yystack.l_mark[0].ast,0);}
break;
case 35:
#line 142 "parser.y"
	{ yyval.ast = astGenerate(AST_LEFT_ASSIGN,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 36:
#line 143 "parser.y"
	{ yyval.ast = astGenerate(AST_LEFT_ASSIGN_VEC,0,yystack.l_mark[-5].ast,yystack.l_mark[-3].ast,yystack.l_mark[0].ast,0);}
break;
case 37:
#line 144 "parser.y"
	{ yyval.ast = astGenerate(AST_RIGHT_ASSIGN,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 38:
#line 145 "parser.y"
	{ yyval.ast = astGenerate(AST_RIGHT_ASSIGN_VEC,0,yystack.l_mark[-5].ast,yystack.l_mark[-3].ast,yystack.l_mark[-1].ast,0);}
break;
case 39:
#line 148 "parser.y"
	{ yyval.ast = astGenerate(AST_PARENTESIS,0,yystack.l_mark[-1].ast,0,0,0);}
break;
case 40:
#line 149 "parser.y"
	{ yyval.ast = yystack.l_mark[0].ast;}
break;
case 41:
#line 150 "parser.y"
	{ yyval.ast = astGenerate(AST_VECTOR,0,yystack.l_mark[-3].ast,yystack.l_mark[-1].ast,0,0);}
break;
case 42:
#line 151 "parser.y"
	{yyval.ast = yystack.l_mark[0].ast;}
break;
case 43:
#line 152 "parser.y"
	{ yyval.ast = astGenerate(AST_FUNCTION,0,yystack.l_mark[-3].ast,yystack.l_mark[-1].ast,0,0);}
break;
case 44:
#line 153 "parser.y"
	{ yyval.ast = astGenerate(AST_NEG,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 45:
#line 154 "parser.y"
	{ yyval.ast = astGenerate(AST_DOLLAR,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 46:
#line 155 "parser.y"
	{ yyval.ast = astGenerate(AST_HASHTAG,0,yystack.l_mark[0].ast,0,0,0);}
break;
case 47:
#line 156 "parser.y"
	{yyval.ast = astGenerate(AST_ADD,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 48:
#line 157 "parser.y"
	{yyval.ast = astGenerate(AST_SUB,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 49:
#line 158 "parser.y"
	{yyval.ast = astGenerate(AST_MULT,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 50:
#line 159 "parser.y"
	{yyval.ast = astGenerate(AST_DIV,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 51:
#line 160 "parser.y"
	{yyval.ast = astGenerate(AST_LESS,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 52:
#line 161 "parser.y"
	{yyval.ast = astGenerate(AST_GREATER,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 53:
#line 162 "parser.y"
	{yyval.ast = astGenerate(AST_OR,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 54:
#line 163 "parser.y"
	{yyval.ast = astGenerate(AST_AND,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 55:
#line 164 "parser.y"
	{yyval.ast = astGenerate(AST_LE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 56:
#line 165 "parser.y"
	{yyval.ast = astGenerate(AST_GE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 57:
#line 166 "parser.y"
	{yyval.ast = astGenerate(AST_EQ,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 58:
#line 167 "parser.y"
	{yyval.ast = astGenerate(AST_DIF,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 59:
#line 170 "parser.y"
	{yyval.ast = yystack.l_mark[0].ast;}
break;
case 60:
#line 171 "parser.y"
	{yyval.ast = 0;}
break;
case 61:
#line 174 "parser.y"
	{yyval.ast = astGenerate(AST_FUNC_ARGUMENTS,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 62:
#line 175 "parser.y"
	{yyval.ast = yystack.l_mark[0].ast;}
break;
case 63:
#line 179 "parser.y"
	{yyval.ast = astGenerate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 64:
#line 183 "parser.y"
	{yyval.ast = astGenerate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 65:
#line 186 "parser.y"
	{yyval.ast = astGenerate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 66:
#line 190 "parser.y"
	{yyval.ast = astGenerate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 67:
#line 191 "parser.y"
	{yyval.ast = astGenerate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0); }
break;
case 68:
#line 192 "parser.y"
	{yyval.ast = astGenerate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0);}
break;
case 69:
#line 193 "parser.y"
	{yyval.ast = astGenerate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0); }
break;
#line 826 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
