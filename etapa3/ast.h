#ifndef AST_HEADER
#define AST_HEADER

#include <stdio.h>

#define NUM_SONS 4 //recomendado

typedef struct ast
{
	struct ast * sons[NUM_SONS];
	int type;

} ast;

ast * astGenerate(int type, ast *s0, ast *s1, ast *s2, ast *s3);
void astPrint(ast *n, int level);
void astMakeCode(ast *n , FILE *f);

#endif