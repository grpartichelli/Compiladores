#ifndef AST_HEADER
#define AST_HEADER

#include <stdio.h>
#include "hash.h"
#define NUM_SONS 4 //recomendado

#define AST_SYMBOL 0




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