#include "ast.h"


ast * astGenerate(int type, node* symbol, ast *s0, ast *s1, ast *s2, ast *s3){
	ast *a;
	
	a =  (ast*) calloc(1,sizeof(ast));
	a->type = type;

	a->sons[0] = s0;
	a->sons[1] = s1;
	a->sons[2] = s2;
	a->sons[3] = s3;

	a->symbol = symbol;

	return a;
}


void astPrint(ast *n, int level){
	if(!n)
		return;

	switch(n->type){
		case AST_SYMBOL: printf("AST_SYMBOL");break;
		default: printf("UNKNOWN DEFAULT");break;

	}

	printf("print");
}

void astMakeCode(ast *n , FILE *f){
	printf("make");
}

