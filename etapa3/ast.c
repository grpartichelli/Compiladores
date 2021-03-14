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
		printf(" ");
	}

	switch(n->type){
		case AST_SYMBOL: printf("AST_SYMBOL=");break;
		case AST_PARENTESIS:printf("AST_PARENTESIS");break;
		case AST_VECTOR: printf("AST_VECTOR");break;
		case AST_EXPR_FUNCTION: printf("AST_FUNCTION");break;
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
		case AST_PRINT: printf("AST_PRINT");break;
		case AST_PRINTLST_STRING: printf("AST_PRINTLST_STRING");break;
		case AST_PRINTLST_EXPR: printf("AST_PRINTLST_EXPR");break;
		case AST_READ: printf("AST_READ");break;
		case AST_RETURN: printf("AST_RETURN");break;
		case AST_IF: printf("AST_IF");break;
		case AST_IFTHEN: printf("AST_IFTHEN");break;
		case AST_WHILE: printf("AST_WHILE");break;
		case AST_BLOCK: printf("AST_BLOCK");break;
		case AST_BLOCKLST: printf("AST_BLOCKLST");break;
		case AST_KW_BOOL: printf("AST_KW_BOOL");break;
		case AST_KW_POINTER: printf("AST_KW_POINTER");break;
		case AST_KW_INT: printf("AST_KW_INT");break;
		case AST_KW_CHAR: printf("AST_KW_CHAR");break;
		case AST_FUNCTION: printf("AST_FUNCTION");break;
		case AST_LST_PAR: printf("AST_LST_PAR");break;
		case AST_LST_PAREND: printf("AST_LST_PAREND");break;
		case AST_DECL_LIT: printf("AST_DECL_LIT");break; 
		case AST_DECL_VEC: printf("AST_DECL_VEC");break; 
		case AST_DECL_VEC_EMPTY: printf("AST_DECL_VEC_EMPTY");break; 
		case AST_LST_VEC1: printf("AST_LST_VEC1");break; 
		case AST_LST_VEC2: printf("AST_LST_VEC2");break; 
		case AST_LST_DECL: printf("AST_LST_DECL");break;
		case AST_LST_FUNC: printf("AST_LST_FUNC");break;
		case AST_LSTEND_DECL: printf("AST_LSTEND_DECL");break;
		case AST_LSTEND_FUNC: printf("AST_LSTEND_FUNC");break;
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
			printf(" ");
		}
		printf("}\n");
	}
	
}

void astMakeCode(ast *n , FILE *f){
	printf("make");
}

