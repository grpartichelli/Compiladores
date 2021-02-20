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
int getLineNumber();
int yylex();
#line 26 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

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
    0,    0,    0,    0,    1,    1,    1,    3,    3,    3,
    3,    4,    4,    4,    4,    5,    5,    2,    6,    6,
    8,    8,    7,    7,    9,    9,   10,   10,   10,   10,
   10,   14,   14,   14,   13,   13,   13,   13,   12,   12,
   12,   12,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   11,   11,   11,   11,   11,   11,
   11,   11,   11,   11,   15,   15,   16,   16,
};
static const YYINT yylen[] = {                            2,
    3,    3,    2,    2,    4,    8,    5,    1,    1,    1,
    1,    1,    1,    1,    1,    2,    0,    6,    1,    0,
    4,    2,    3,    1,    3,    2,    2,    2,    1,    2,
    1,    6,    8,    5,    1,    1,    3,    3,    3,    6,
    3,    6,    3,    1,    4,    1,    1,    1,    1,    4,
    2,    2,    2,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    9,   10,    8,   11,    0,    0,    0,    0,    0,    0,
    0,    0,    1,    2,    0,    0,    0,   12,   13,   14,
   15,    5,    0,    0,   19,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   46,   48,   49,   47,
    0,    0,    0,    0,    0,   18,   24,    0,   29,   31,
    0,   21,    0,    0,   27,    0,    0,    0,   30,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   65,   43,    0,   23,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,    0,
    0,    0,   37,   38,    0,    0,   50,   25,    0,   16,
    0,   34,   45,    0,   67,    0,    0,    0,   42,    0,
   33,
};
static const YYINT yydgoto[] = {                          5,
    6,    7,    8,  108,  109,   24,   65,   25,   66,   47,
   48,   49,   59,   50,   91,   92,
};
static const YYINT yysindex[] = {                      -131,
    0,    0,    0,    0,    0,  -56,  -43,  -89, -131, -131,
  -32, -248,    0,    0, -143, -131,  -63,    0,    0,    0,
    0,    0, -242,   -8,    0, -233,    5,  -29,  -16, -131,
   11,   16, -229,  -35,  -23,  -22,    0,    0,    0,    0,
  -23,  -29,  -23,  -23,  -23,    0,    0,    1,    0,    0,
 -143,    0,  -23,  -23,    0,  -25,   24,   32,    0,  160,
  -23,  -23,  -23,   40,   14,  -54,  160,  160,  160,  -23,
  -23,  -23,  -23, -210,  -23,  -23,  -23,  -23,  -23,  -23,
  -23, -143,   63,   71,  -23,  -35,  -35,  160,   77,  103,
   43,    0,    0,  -29,    0,  160,  160,  160,  160,   -3,
  160,  160,  160,  160,  160,  160,  160, -143,    0, -173,
  -29,  133,    0,    0, -182,  -23,    0,    0,  -23,    0,
  -29,    0,    0,  -23,    0,  174, -170,  160,    0,  -29,
    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,   95,   96,
    0,    0,    0,    0,    0,   57,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   58,    0,   48,    0,
    0,    0,    0,    0,    0,   12,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   -7,  -55,  -50,    0,  -49,
    0,    0,   61,    0,    0,    0,  113,  118,  125,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   52,    0,    0,    0,    0,    0,  -40,    0,   80,
    0,    0,    0,   17,    0,  235,  263,  271,  276,  -39,
  277,  285,  316,  318,  324,  341,  346,   52,    0,    0,
    0,    0,    0,    0,   20,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   79,  -38,    0,    0,
    0,
};
static const YYINT yygindex[] = {                        13,
    0,    0,   -2,    9,   31,    0,   19,  121,   49,    0,
  406,    0,  -61,    0,    0,   36,
};
#define YYTABLESIZE 619
static const YYINT yytable[] = {                         45,
   44,   12,    9,   35,   41,   45,   44,   16,   36,   28,
   41,   45,   44,   23,   63,   10,   41,   63,   39,   41,
   40,   13,   14,   22,  113,  114,   17,   23,   15,   26,
   44,   27,   28,   44,   44,   44,   44,   44,   81,   44,
   29,   51,   77,   75,   55,   76,   46,   78,   30,   44,
   53,   44,   44,   44,   44,   54,   44,   45,   44,   82,
   79,   45,   45,  100,   45,   85,   45,   86,   62,   81,
   95,   44,   94,   77,   75,   87,   76,   81,   78,   45,
   93,   77,   75,  117,   76,   44,   78,  119,  121,  124,
   43,   79,  130,   42,    3,    4,   43,   20,   22,   79,
   81,   66,   43,  110,   77,   75,    7,   76,   81,   78,
   17,  111,   77,   75,   81,   76,   44,   78,   77,   75,
   68,   76,   79,   78,   80,    1,    2,    3,    4,  122,
   79,   18,   19,   20,   21,   44,   79,   32,  120,  127,
   81,   26,  118,   45,   77,   75,  116,   76,  131,   78,
   52,  125,    0,   51,    0,   80,   51,    0,   52,    0,
    0,   52,   79,   80,    0,   53,    0,    0,   53,  115,
   81,   51,    0,    0,   77,   75,   52,   76,    0,   78,
    0,    0,    0,   53,   11,    0,   80,    0,    0,    0,
    0,    0,   79,    0,   80,    0,    0,   81,    0,    0,
   80,   77,   75,    0,   76,   51,   78,   35,    0,    0,
   52,   81,   36,   28,    0,   77,   75,   53,   76,   79,
   78,    0,   39,   41,   40,  123,   80,    0,    0,    0,
    0,   31,    0,   79,   32,   33,   34,   35,   56,   37,
   38,   39,   40,   57,   36,   37,   38,   39,   40,   61,
   56,   37,   38,   39,   40,   44,   80,    0,    0,    0,
   44,   44,   44,   44,    0,   44,  129,    0,   70,   71,
   72,   73,    0,   74,    0,   61,    0,    0,   61,   44,
   44,   44,   44,   80,   44,    0,    0,   45,   45,   45,
   45,    0,   45,   61,    0,    0,    0,   80,    0,   70,
   71,   72,   73,   62,    0,    0,   62,   70,   71,   72,
   73,   63,    0,    0,   63,    0,   64,   54,    0,   64,
   54,   62,    0,    0,    0,   55,    0,   61,   55,   63,
   70,   71,   72,   73,   64,   54,    0,    0,   70,   71,
   72,   73,    0,   55,   70,   71,   72,   73,    0,    0,
    0,    0,    0,    0,    0,   62,   56,    0,   57,   56,
    0,   57,    0,   63,   58,    0,    0,   58,   64,   54,
   70,   71,   72,   73,   56,   51,   57,   55,    0,    0,
   52,   59,   58,    0,   59,   51,   60,   53,    0,   60,
   52,    0,    0,    0,    0,    0,    0,   53,    0,   59,
   70,   71,   72,   73,   60,    0,    0,    0,   56,    0,
   57,    0,    0,    0,    0,    0,   58,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   70,   71,   72,
   73,    0,    0,   59,    0,    0,    0,    0,   60,   58,
   60,   70,   71,   72,   73,    0,   64,    0,   67,   68,
   69,    0,    0,    0,    0,    0,    0,    0,   83,   84,
    0,    0,    0,    0,    0,    0,   88,   89,   90,    0,
    0,    0,    0,    0,    0,   96,   97,   98,   99,    0,
  101,  102,  103,  104,  105,  106,  107,    0,    0,    0,
  112,   58,   58,    0,    0,    0,    0,   61,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   61,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   90,    0,    0,  126,   62,    0,    0,    0,  128,
    0,    0,    0,   63,    0,   62,    0,    0,   64,   54,
    0,    0,    0,   63,    0,    0,    0,   55,   64,   54,
    0,    0,    0,    0,    0,    0,    0,   55,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   56,    0,
   57,    0,    0,    0,    0,    0,   58,    0,   56,    0,
   57,    0,    0,    0,    0,    0,   58,    0,    0,    0,
    0,    0,    0,   59,    0,    0,    0,    0,   60,    0,
    0,    0,    0,   59,    0,    0,    0,    0,   60,
};
static const YYINT yycheck[] = {                         35,
   36,   91,   59,   59,   40,   35,   36,   40,   59,   59,
   40,   35,   36,   16,   40,   59,   40,   40,   59,   59,
   59,    9,   10,   15,   86,   87,  275,   30,   61,   93,
   38,  274,   41,   41,   42,   43,   44,   45,   38,   47,
  274,   58,   42,   43,  274,   45,   28,   47,   44,   38,
   40,   59,   60,   42,   43,   40,   45,   38,   47,   51,
   60,   42,   43,  274,   45,   91,   47,   44,   91,   38,
  125,   60,   59,   42,   43,   44,   45,   38,   47,   60,
   41,   42,   43,   41,   45,   93,   47,   91,  262,  272,
  126,   60,  263,  123,    0,    0,  126,   41,   41,   60,
   38,   41,  126,   41,   42,   43,   59,   45,   38,   47,
   59,   41,   42,   43,   38,   45,  124,   47,   42,   43,
   41,   45,   60,   47,  124,  257,  258,  259,  260,  111,
   60,  275,  276,  277,  278,  124,   60,   59,  108,  121,
   38,  125,   94,  124,   42,   43,   44,   45,  130,   47,
   30,  116,   -1,   41,   -1,  124,   44,   -1,   41,   -1,
   -1,   44,   60,  124,   -1,   41,   -1,   -1,   44,   93,
   38,   59,   -1,   -1,   42,   43,   59,   45,   -1,   47,
   -1,   -1,   -1,   59,  274,   -1,  124,   -1,   -1,   -1,
   -1,   -1,   60,   -1,  124,   -1,   -1,   38,   -1,   -1,
  124,   42,   43,   -1,   45,   93,   47,  263,   -1,   -1,
   93,   38,  263,  263,   -1,   42,   43,   93,   45,   60,
   47,   -1,  263,  263,  263,   93,  124,   -1,   -1,   -1,
   -1,  261,   -1,   60,  264,  265,  266,  267,  274,  275,
  276,  277,  278,  279,  274,  275,  276,  277,  278,  272,
  274,  275,  276,  277,  278,  263,  124,   -1,   -1,   -1,
  268,  269,  270,  271,   -1,  273,   93,   -1,  268,  269,
  270,  271,   -1,  273,   -1,   41,   -1,   -1,   44,  268,
  269,  270,  271,  124,  273,   -1,   -1,  268,  269,  270,
  271,   -1,  273,   59,   -1,   -1,   -1,  124,   -1,  268,
  269,  270,  271,   41,   -1,   -1,   44,  268,  269,  270,
  271,   41,   -1,   -1,   44,   -1,   41,   41,   -1,   44,
   44,   59,   -1,   -1,   -1,   41,   -1,   93,   44,   59,
  268,  269,  270,  271,   59,   59,   -1,   -1,  268,  269,
  270,  271,   -1,   59,  268,  269,  270,  271,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   93,   41,   -1,   41,   44,
   -1,   44,   -1,   93,   41,   -1,   -1,   44,   93,   93,
  268,  269,  270,  271,   59,  263,   59,   93,   -1,   -1,
  263,   41,   59,   -1,   44,  273,   41,  263,   -1,   44,
  273,   -1,   -1,   -1,   -1,   -1,   -1,  273,   -1,   59,
  268,  269,  270,  271,   59,   -1,   -1,   -1,   93,   -1,
   93,   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,  270,
  271,   -1,   -1,   93,   -1,   -1,   -1,   -1,   93,   34,
   35,  268,  269,  270,  271,   -1,   41,   -1,   43,   44,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   53,   54,
   -1,   -1,   -1,   -1,   -1,   -1,   61,   62,   63,   -1,
   -1,   -1,   -1,   -1,   -1,   70,   71,   72,   73,   -1,
   75,   76,   77,   78,   79,   80,   81,   -1,   -1,   -1,
   85,   86,   87,   -1,   -1,   -1,   -1,  263,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  273,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  116,   -1,   -1,  119,  263,   -1,   -1,   -1,  124,
   -1,   -1,   -1,  263,   -1,  273,   -1,   -1,  263,  263,
   -1,   -1,   -1,  273,   -1,   -1,   -1,  263,  273,  273,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  273,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,
  263,   -1,   -1,   -1,   -1,   -1,  263,   -1,  273,   -1,
  273,   -1,   -1,   -1,   -1,   -1,  273,   -1,   -1,   -1,
   -1,   -1,   -1,  263,   -1,   -1,   -1,   -1,  263,   -1,
   -1,   -1,   -1,  273,   -1,   -1,   -1,   -1,  273,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 280
#define YYUNDFTOKEN 299
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'#'","'$'",0,"'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,
0,0,0,0,"':'","';'","'<'","'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_CHAR","KW_INT","KW_BOOL",
"KW_POINTER","KW_IF","KW_THEN","KW_ELSE","KW_WHILE","KW_READ","KW_PRINT",
"KW_RETURN","OPERATOR_LE","OPERATOR_GE","OPERATOR_EQ","OPERATOR_DIF",
"LEFT_ASSIGN","RIGHT_ASSIGN","TK_IDENTIFIER","LIT_INTEGER","LIT_TRUE",
"LIT_FALSE","LIT_CHAR","LIT_STRING","TOKEN_ERROR",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"programa : variable ';' programa",
"programa : function ';' programa",
"programa : variable ';'",
"programa : function ';'",
"variable : type TK_IDENTIFIER '=' varlit",
"variable : type '[' LIT_INTEGER ']' TK_IDENTIFIER ':' varlit vector_value",
"variable : type '[' LIT_INTEGER ']' TK_IDENTIFIER",
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
"command : simple",
"block : command ';' block",
"block : command ';'",
"simple : KW_READ TK_IDENTIFIER",
"simple : KW_RETURN expr",
"simple : assign",
"simple : KW_PRINT print",
"simple : flow_control",
"flow_control : KW_IF '(' expr ')' KW_THEN command",
"flow_control : KW_IF '(' expr ')' KW_THEN command KW_ELSE command",
"flow_control : KW_WHILE '(' expr ')' command",
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
#line 158 "parser.y"

int yyerror(){
	
	printf("Erro de sintaxe na linha %d\n",getLineNumber());
	exit(3);
}
#line 432 "y.tab.c"

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
