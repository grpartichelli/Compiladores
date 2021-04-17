#ifndef AST_HEADER
#define AST_HEADER

#include <stdio.h>
#include "hash.h"
#define NUM_SONS 4 //recomendado


#define AST_PARENTESIS 1
#define AST_VECTOR 2
#define AST_EXPR_FUNCTION 3

#define AST_NEG 4
#define AST_DOLLAR 5
#define AST_HASHTAG 6

#define AST_ADD 7
#define AST_SUB 8
#define AST_MULT 9
#define AST_DIV 10
#define AST_LESS 11
#define AST_GREATER 12
#define AST_OR 13
#define AST_AND 14

#define AST_LE 15
#define AST_GE 16
#define AST_EQ 17
#define AST_DIF 18

#define AST_FUNC_ARGUMENTS 19

#define AST_LEFT_ASSIGN 20
#define AST_RIGHT_ASSIGN 21
#define AST_LEFT_ASSIGN_VEC 22
#define AST_RIGHT_ASSIGN_VEC 23

#define AST_PRINT 24
#define AST_PRINTLST_STRING 25
#define AST_PRINTLST_EXPR 26
#define AST_READ 27
#define AST_RETURN 28
#define AST_IF 29
#define AST_IFELSE 30
#define AST_WHILE 31
#define AST_BLOCK 32
#define AST_BLOCKLST 33

#define AST_KW_BOOL 34
#define AST_KW_POINTER 35
#define AST_KW_INT 36
#define AST_KW_CHAR 37

#define AST_FUNCTION 38
#define AST_LST_PAR 39
#define AST_LST_PAREND 40

#define AST_DECL_LIT 41
#define AST_DECL_VEC 42
#define AST_DECL_VEC_EMPTY 43
#define AST_LST_VEC1 44 
#define AST_LST_VEC2 45

#define AST_LST_DECL 46
#define AST_LST_FUNC 47
#define AST_LSTEND_DECL 48
#define AST_LSTEND_FUNC 49

#define AST_SYMBOL_INT 50
#define AST_SYMBOL_CHAR 51
#define AST_SYMBOL_TRUE 52
#define AST_SYMBOL_FALSE 53
#define AST_SYMBOL_IDENTIFIER 54
#define AST_SYMBOL_STRING 55




typedef struct ast
{
	struct ast * sons[NUM_SONS];
	node *symbol;
	int type;

} ast;

ast * astGenerate(int type, node* symbol, ast *s0, ast *s1, ast *s2, ast *s3);
void astPrint(ast *n, int level);
void astMakeCode(ast *n , FILE *f);

#endif