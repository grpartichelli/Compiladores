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
#line 10 "parser.y"
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
#line 40 "y.tab.c"

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
    0,    1,    1,    1,    1,    2,    2,    2,    4,    4,
    4,    4,    5,    5,    5,    5,    6,    6,    3,    7,
    7,    9,    9,    8,    8,    8,    8,    8,    8,    8,
    8,    8,   10,   10,   13,   13,   13,   13,   12,   12,
   12,   12,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   14,   14,   15,   15,
};
static const YYINT yylen[] = {                            2,
    1,    3,    3,    2,    2,    4,    8,    5,    1,    1,
    1,    1,    1,    1,    1,    1,    2,    0,    6,    1,
    0,    4,    2,    3,    2,    2,    1,    2,    6,    8,
    5,    0,    3,    0,    1,    1,    3,    3,    3,    6,
    3,    6,    3,    1,    4,    1,    1,    1,    1,    4,
    2,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         0,
   10,   11,    9,   12,    0,    1,    0,    0,    0,    0,
    0,    0,    0,    2,    3,    0,    0,    0,   13,   14,
   15,   16,    6,    0,    0,   20,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   46,   48,   49,
   47,    0,    0,    0,    0,    0,   19,    0,   27,    0,
   22,    0,    0,   25,    0,    0,    0,   28,    0,    0,
    0,    0,   53,   52,   51,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   66,   43,    0,   24,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   56,   57,    0,    7,
    0,    0,    0,   37,   38,    0,    0,   50,   33,    0,
   17,    0,   31,   45,    0,   68,    0,    0,    0,   42,
    0,   30,
};
static const YYINT yydgoto[] = {                          5,
    6,    7,    8,    9,  109,  110,   25,   67,   26,   68,
   48,   49,   58,   91,   92,
};
static const YYINT yysindex[] = {                      -178,
    0,    0,    0,    0,    0,    0,  -40,  -36,  -82, -178,
 -178,  -37, -228,    0,    0, -118, -178,  -31,    0,    0,
    0,    0,    0, -223,   17,    0, -206,   28,  -29,   15,
 -178,   34,   43, -186,  -35,  -23,  -14,    0,    0,    0,
    0,  -23,  -23,  -23,  -23,  -29,    0,  135,    0, -118,
    0,  -23,  -23,    0,  -20,   46,  353,    0,  503,  -23,
  -23,  -23,    0,    0,    0,  378,   37,  -32,  -23,  -23,
  -23,  -23, -175,  -23,  -23,  -23,  -23,  -23,  -23,  -23,
  -23, -118,  386,  409,  -23,  -35,  -35,  503,  419,  444,
   59,    0,    0,  -29,    0,  -15,  -15,  -15,  -15,   11,
  324,  324,  -15,  -15,  -18,  -18,    0,    0, -118,    0,
 -157,  -29,  454,    0,    0, -166,  -23,    0,    0,  -23,
    0,  -29,    0,    0,  -23,    0,  493, -155,  503,    0,
  -29,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  112,
  114,    0,    0,    0,    0,    0,   74,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   78,   61,   69,
    0,    0,    0,    0,    0,    0,  141,    0,    0,    0,
    0,    0,    0,    0,    0,  -55,    0,    0,    0,    0,
    0,    0,    0,    0,   -7,  -57,  -51,    0,  -49,    0,
    0,   90,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   73,    0,    0,    0,    0,    0,  -45,    0,   93,
    0,    0,    0,  -55,    0,   25,   51,   63,   83,  -44,
  264,  266,   92,  109,    5,   16,    0,    0,   73,    0,
    0,  -43,    0,    0,    0,  166,    0,    0,    0,    0,
    0,  -43,    0,    0,    0,    0,    0,   79,  -41,    0,
  -43,    0,
};
static const YYINT yygindex[] = {                         0,
   31,    0,    0,    8,    6,   30,    0,    4,  106,   47,
  623,    0,  -42,    0,   29,
};
#define YYTABLESIZE 774
static const YYINT yytable[] = {                         42,
   43,   35,   17,   32,   45,   42,   43,   36,   13,   26,
   45,   42,   43,   39,   41,   32,   45,   40,   10,   62,
   16,   23,   11,   80,   24,   62,   80,   78,   81,   79,
   44,   81,   47,   44,   44,   44,   44,   44,   24,   44,
   14,   15,   54,  114,  115,   54,   18,   54,   54,   54,
   28,   44,   44,   55,   44,   82,   55,   29,   55,   55,
   55,   27,   62,   54,   54,   62,   54,   30,   62,   34,
   85,   31,   50,   52,   55,   55,   61,   55,    1,    2,
    3,    4,   53,   62,   62,   44,   62,   54,   63,   86,
   44,   63,   95,   46,   63,   94,   44,   54,  100,  118,
   64,  120,   44,   64,  122,  125,   64,  131,   55,   63,
   63,    4,   63,    5,   21,  123,   44,   62,   23,   32,
   65,   64,   64,   65,   64,  128,   65,    8,   54,   58,
   67,   18,   58,   69,  132,   58,   51,   29,  121,   55,
  119,   65,   65,   63,   65,  126,   59,    0,   62,   59,
   58,   58,   59,   58,    0,   64,   19,   20,   21,   22,
    0,    0,    0,    0,    0,    0,    0,   59,   59,    0,
   59,    0,   75,    0,   63,   65,   80,   78,   44,   79,
    0,   81,   44,   44,   58,   44,   64,   44,    0,    0,
    0,   12,    0,    0,   76,    0,   77,    0,    0,    0,
   44,   59,   44,   45,    0,   35,   65,   45,   45,    0,
   45,   36,   45,   26,    0,   58,    0,   39,   41,   32,
    0,   40,    0,    0,    0,   45,    0,   45,    0,    0,
    0,   32,   59,    0,   33,   34,   35,   36,   55,   38,
   39,   40,   41,   56,   37,   38,   39,   40,   41,    0,
   55,   38,   39,   40,   41,   44,    0,   60,   74,    0,
   44,   44,   44,   44,   44,   44,    0,   54,    0,    0,
    0,    0,   54,   54,   54,   54,    0,   54,   55,    0,
    0,    0,    0,   55,   55,   55,   55,   62,   55,   45,
    0,    0,   62,   62,   62,   62,    0,   62,    0,    0,
    0,   60,    0,   61,   60,    0,   61,   60,    0,   61,
    0,    0,    0,   63,    0,    0,    0,    0,   63,   63,
   63,   63,   60,   63,   61,   64,    0,    0,    0,    0,
   64,   64,   64,   64,    0,   64,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   65,    0,    0,    0,    0,
   65,   65,   65,   65,   58,   65,   60,    0,   61,   58,
   58,   58,   58,    0,   58,   80,   78,    0,   79,    0,
   81,   59,    0,    0,    0,    0,   59,   59,   59,   59,
    0,   59,    0,   76,    0,   77,    0,   60,    0,   61,
   75,    0,    0,    0,   80,   78,   87,   79,    0,   81,
    0,    0,   69,   70,   71,   72,    0,   73,   44,   44,
   44,   44,   76,   44,   77,   75,    0,    0,   93,   80,
   78,    0,   79,   75,   81,    0,  111,   80,   78,    0,
   79,    0,   81,   45,   45,   45,   45,   76,   45,   77,
    0,    0,    0,    0,    0,   76,   75,   77,    0,  112,
   80,   78,    0,   79,    0,   81,   75,    0,    0,    0,
   80,   78,    0,   79,    0,   81,    0,    0,   76,    0,
   77,    0,    0,    0,    0,    0,   74,    0,   76,    0,
   77,   75,    0,    0,    0,   80,   78,  117,   79,    0,
   81,   75,    0,    0,    0,   80,   78,    0,   79,    0,
   81,   74,    0,   76,    0,   77,    0,    0,    0,   74,
    0,  116,    0,   76,    0,   77,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   60,    0,   61,    0,
   75,    0,   74,    0,   80,   78,   60,   79,   61,   81,
   75,    0,   74,    0,   80,   78,  124,   79,    0,   81,
    0,    0,   76,    0,   77,    0,    0,    0,    0,    0,
    0,    0,   76,    0,   77,    0,    0,   74,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   74,    0,    0,
    0,    0,    0,    0,    0,  130,    0,    0,    0,    0,
    0,   69,   70,   71,   72,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   74,    0,    0,    0,
   69,   70,   71,   72,    0,    0,   74,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   69,   70,   71,   72,    0,
    0,    0,    0,   69,   70,   71,   72,   57,   59,    0,
    0,    0,    0,    0,   63,   64,   65,   66,    0,    0,
    0,    0,    0,    0,   83,   84,   69,   70,   71,   72,
    0,    0,   88,   89,   90,    0,   69,   70,   71,   72,
    0,   96,   97,   98,   99,    0,  101,  102,  103,  104,
  105,  106,  107,  108,    0,    0,    0,  113,   57,   57,
    0,   69,   70,   71,   72,    0,    0,    0,    0,    0,
    0,   69,   70,   71,   72,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   90,
    0,    0,  127,    0,    0,    0,    0,  129,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   69,   70,   71,   72,    0,    0,    0,    0,    0,    0,
   69,   70,   71,   72,
};
static const YYINT yycheck[] = {                         35,
   36,   59,   40,   59,   40,   35,   36,   59,   91,   59,
   40,   35,   36,   59,   59,   59,   40,   59,   59,   40,
   58,   16,   59,   42,   17,   40,   42,   43,   47,   45,
   38,   47,   29,   41,   42,   43,   44,   45,   31,   47,
   10,   11,   38,   86,   87,   41,  275,   43,   44,   45,
  274,   59,   60,   38,   62,   50,   41,   41,   43,   44,
   45,   93,   38,   59,   60,   41,   62,  274,   44,  125,
   91,   44,   58,   40,   59,   60,   91,   62,  257,  258,
  259,  260,   40,   59,   60,   93,   62,  274,   38,   44,
  126,   41,  125,  123,   44,   59,  126,   93,  274,   41,
   38,   91,  126,   41,  262,  272,   44,  263,   93,   59,
   60,    0,   62,    0,   41,  112,  124,   93,   41,   59,
   38,   59,   60,   41,   62,  122,   44,   59,  124,   38,
   41,   59,   41,   41,  131,   44,   31,   59,  109,  124,
   94,   59,   60,   93,   62,  117,   38,   -1,  124,   41,
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
   38,   -1,  124,   -1,   42,   43,   93,   45,   -1,   47,
   -1,   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   60,   -1,   62,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,
   -1,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,
  268,  269,  270,  271,   -1,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  268,  269,  270,  271,   -1,
   -1,   -1,   -1,  268,  269,  270,  271,   35,   36,   -1,
   -1,   -1,   -1,   -1,   42,   43,   44,   45,   -1,   -1,
   -1,   -1,   -1,   -1,   52,   53,  268,  269,  270,  271,
   -1,   -1,   60,   61,   62,   -1,  268,  269,  270,  271,
   -1,   69,   70,   71,   72,   -1,   74,   75,   76,   77,
   78,   79,   80,   81,   -1,   -1,   -1,   85,   86,   87,
   -1,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  117,
   -1,   -1,  120,   -1,   -1,   -1,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  268,  269,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,
  268,  269,  270,  271,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 298
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
0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : inicio",
"inicio : programa",
"programa : decl ';' programa",
"programa : function ';' programa",
"programa : decl ';'",
"programa : function ';'",
"decl : type TK_IDENTIFIER ':' varlit",
"decl : type '[' LIT_INTEGER ']' TK_IDENTIFIER ':' varlit vector_value",
"decl : type '[' LIT_INTEGER ']' TK_IDENTIFIER",
"type : KW_BOOL",
"type : KW_CHAR",
"type : KW_INT",
"type : KW_POINTER",
"varlit : LIT_INTEGER",
"varlit : LIT_TRUE",
"varlit : LIT_FALSE",
"varlit : LIT_CHAR",
"vector_value : varlit vector_value",
"vector_value :",
"function : type TK_IDENTIFIER '(' parameters ')' command",
"parameters : listparameters",
"parameters :",
"listparameters : type TK_IDENTIFIER ',' listparameters",
"listparameters : type TK_IDENTIFIER",
"command : '{' block '}'",
"command : KW_READ TK_IDENTIFIER",
"command : KW_RETURN expr",
"command : assign",
"command : KW_PRINT print",
"command : KW_IF '(' expr ')' KW_THEN command",
"command : KW_IF '(' expr ')' KW_THEN command KW_ELSE command",
"command : KW_WHILE '(' expr ')' command",
"command :",
"block : command ';' block",
"block :",
"print : LIT_STRING",
"print : expr",
"print : LIT_STRING ',' print",
"print : expr ',' print",
"assign : TK_IDENTIFIER LEFT_ASSIGN expr",
"assign : TK_IDENTIFIER '[' expr ']' LEFT_ASSIGN expr",
"assign : expr RIGHT_ASSIGN TK_IDENTIFIER",
"assign : expr RIGHT_ASSIGN TK_IDENTIFIER '[' expr ']'",
"expr : '(' expr ')'",
"expr : TK_IDENTIFIER",
"expr : TK_IDENTIFIER '[' expr ']'",
"expr : LIT_INTEGER",
"expr : LIT_CHAR",
"expr : LIT_TRUE",
"expr : LIT_FALSE",
"expr : TK_IDENTIFIER '(' func_arguments ')'",
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
#line 177 "parser.y"

int yyerror(){
	
	printf("Erro de sintaxe na linha %d\n",getLineNumber());
	exit(3);
}

void loadOutFile(FILE *saida){
	printf("Hey!");
}
#line 477 "y.tab.c"

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
