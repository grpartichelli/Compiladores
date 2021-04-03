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
extern YYSTYPE yylval;
