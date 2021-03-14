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

	for(int i=0;i<level;i++){
		printf("  ");
	}

	switch(n->type){
		case AST_SYMBOL: printf("AST_SYMBOL=");break;
		case AST_PARENTESIS:printf("AST_PARENTESIS");break;
		case AST_VECTOR: printf("AST_VECTOR");break;
		case AST_FUNCTION: printf("AST_FUNCTION");break;
		case AST_NEG: printf("AST_NEG");break;
		case AST_DOLLAR: printf("AST_DOLLAR");break;
		case AST_HASHTAG: printf("AST_HASHTAG");break;
		case AST_ADD: printf("AST_ADD");break;
		case AST_SUB: printf("AST_SUB");break;
		case AST_MULT: printf("AST_MULT");break;
		case AST_DIV: printf("AST_DIV");break;
		case AST_LESS: printf("AST_LESS");break;
		case AST_GREATER: printf("AST_GREATER");break;
		case AST_OR: printf("AST_OR");break;
		case AST_AND: printf("AST_AND");break;
		case AST_LE: printf("AST_LE");break;
		case AST_GE: printf("AST_GE");break;
		case AST_EQ: printf("AST_EQ");break;
		case AST_DIF: printf("AST_DIF");break;
		case AST_FUNC_ARGUMENTS: printf("AST_FUNC_ARGUMENTS");break;
		case AST_LEFT_ASSIGN: printf("AST_LEFT_ASSIGN");break;
		case AST_RIGHT_ASSIGN: printf("AST_RIGHT_ASSIGN");break;
		case AST_LEFT_ASSIGN_VEC: printf("AST_LEFT_ASSIGN_VEC");break;
		case AST_RIGHT_ASSIGN_VEC: printf("AST_RIGHT_ASSIGN_VEC");break;
		default: printf("UNKNOWN DEFAULT");break;

	}


	if(n->symbol){
		printf("%s\n", n->symbol->content);
	}
	else{
		printf("{\n");
	}



	for(int i=0;i<NUM_SONS; i++){
		astPrint(n->sons[i],level+1);
	}


	if(!n->symbol){
		for(int i=0;i<level;i++){
			printf("  ");
		}
		printf("}\n");
	}
	
}

void astMakeCode(ast *n , FILE *f){
	printf("make");
}

