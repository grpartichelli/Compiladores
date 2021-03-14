#ifndef AST_HEADER
#define AST_HEADER

#include <stdio.h>
#include "hash.h"
#define NUM_SONS 4 //recomendado

#define AST_SYMBOL 0
#define AST_PARENTESIS 1
#define AST_VECTOR 2
#define AST_FUNCTION 3

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