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
		case AST_IFELSE: printf("AST_IFELSE");break;
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
	if(!n)
		return;

	switch(n->type){
		case AST_SYMBOL: 
			fprintf(f," %s ",n->symbol->content);
		break;

		case AST_PARENTESIS:
			fprintf(f,"(");
			astMakeCode(n->sons[0],f);
			fprintf(f,")");
		break;

		case AST_VECTOR: 
			astMakeCode(n->sons[0],f);
			fprintf(f,"[");astMakeCode(n->sons[1],f);fprintf(f,"]");
		break;

		case AST_EXPR_FUNCTION: 
			astMakeCode(n->sons[0],f);
			fprintf(f,"(");astMakeCode(n->sons[1],f);fprintf(f,")");	
		break;

		case AST_NEG: fprintf(f,"~");astMakeCode(n->sons[0],f);break;
		case AST_DOLLAR: fprintf(f,"$");astMakeCode(n->sons[0],f);break;
		case AST_HASHTAG: fprintf(f,"#");astMakeCode(n->sons[0],f);break;

		case AST_ADD: astMakeCode(n->sons[0],f);fprintf(f,"+");astMakeCode(n->sons[1],f);break;
		case AST_SUB:  astMakeCode(n->sons[0],f);fprintf(f,"-");astMakeCode(n->sons[1],f);break;
		case AST_MULT:  astMakeCode(n->sons[0],f);fprintf(f,"*");astMakeCode(n->sons[1],f);break;
		case AST_DIV:  astMakeCode(n->sons[0],f);fprintf(f,"/");astMakeCode(n->sons[1],f);break;
		case AST_LESS: astMakeCode(n->sons[0],f);fprintf(f,"<");astMakeCode(n->sons[1],f);break;
		case AST_GREATER: astMakeCode(n->sons[0],f);fprintf(f,">");astMakeCode(n->sons[1],f);break;
		case AST_OR: astMakeCode(n->sons[0],f);fprintf(f,"|");astMakeCode(n->sons[1],f);break;
		case AST_AND: astMakeCode(n->sons[0],f);fprintf(f,"&");astMakeCode(n->sons[1],f);break;
		case AST_LE: astMakeCode(n->sons[0],f);fprintf(f,"<=");astMakeCode(n->sons[1],f);break;
		case AST_GE: astMakeCode(n->sons[0],f);fprintf(f,">=");astMakeCode(n->sons[1],f);break;
		case AST_EQ: astMakeCode(n->sons[0],f);fprintf(f,"==");astMakeCode(n->sons[1],f);break;
		case AST_DIF: astMakeCode(n->sons[0],f);fprintf(f,"!=");astMakeCode(n->sons[1],f);break;
		case AST_FUNC_ARGUMENTS: 
			astMakeCode(n->sons[0],f);
			fprintf(f,",");
			astMakeCode(n->sons[1],f);
		break;
		case AST_LEFT_ASSIGN: 
			astMakeCode(n->sons[0],f);
			fprintf(f,"<-");
			astMakeCode(n->sons[1],f);
		break;
		case AST_RIGHT_ASSIGN:
			astMakeCode(n->sons[0],f);
			fprintf(f,"->");
			astMakeCode(n->sons[1],f);
		break;
		case AST_LEFT_ASSIGN_VEC: 
			astMakeCode(n->sons[0],f);
			fprintf(f,"["); astMakeCode(n->sons[1],f); fprintf(f,"]");
			fprintf(f,"<-");
			astMakeCode(n->sons[2],f);
		break;
		case AST_RIGHT_ASSIGN_VEC: 
			astMakeCode(n->sons[0],f);
			fprintf(f,"->");
			fprintf(f,"["); astMakeCode(n->sons[1],f); fprintf(f,"]");
			astMakeCode(n->sons[2],f);
		break;

		case AST_PRINT: fprintf(f,"print ");astMakeCode(n->sons[0],f);break;
		case AST_PRINTLST_STRING: 
			astMakeCode(n->sons[0],f);fprintf(f,",");astMakeCode(n->sons[1],f);
		break;	
		case AST_PRINTLST_EXPR: 
			astMakeCode(n->sons[0],f);fprintf(f,",");astMakeCode(n->sons[1],f);
		break;	

		case AST_READ: fprintf(f,"read ");astMakeCode(n->sons[0],f);break;
		case AST_RETURN: fprintf(f,"return ");astMakeCode(n->sons[0],f);break;
		case AST_IF: 
			fprintf(f,"if(");astMakeCode(n->sons[0],f);fprintf(f,")");
			fprintf(f,"then ");astMakeCode(n->sons[1],f);
		break;
		case AST_IFELSE:
			fprintf(f,"if(");astMakeCode(n->sons[0],f);fprintf(f,")");
			fprintf(f,"then ");astMakeCode(n->sons[1],f);
			fprintf(f,"else ");astMakeCode(n->sons[2],f);
		break;
		case AST_WHILE: 
			fprintf(f,"while(");astMakeCode(n->sons[0],f);
			fprintf(f,")");astMakeCode(n->sons[1],f);
		break;
		case AST_BLOCK: 
			fprintf(f,"{");
			astMakeCode(n->sons[0],f);
			fprintf(f,"}");
		break;
		case AST_BLOCKLST: 
			astMakeCode(n->sons[0],f);
			fprintf(f,";\n");
			astMakeCode(n->sons[1],f);
		break;
		case AST_KW_BOOL: fprintf(f,"bool");break;
		case AST_KW_POINTER: fprintf(f,"pointer");break;
		case AST_KW_INT: fprintf(f,"int");break;
		case AST_KW_CHAR: fprintf(f,"char");break;
		case AST_FUNCTION: 
			astMakeCode(n->sons[0],f);
			astMakeCode(n->sons[1],f);
			fprintf(f,"(");
			astMakeCode(n->sons[2],f);
			fprintf(f,")");
			astMakeCode(n->sons[3],f);
		break;

		case AST_LST_PAR: 
			astMakeCode(n->sons[0],f);
			astMakeCode(n->sons[1],f);
			fprintf(f,",");
			astMakeCode(n->sons[2],f);
		break;
		case AST_LST_PAREND: 
			astMakeCode(n->sons[0],f);
			astMakeCode(n->sons[1],f);
		break;

		case AST_DECL_LIT: 
			astMakeCode(n->sons[0],f);
			astMakeCode(n->sons[1],f);
			fprintf(f,":");
			astMakeCode(n->sons[2],f);
		break; 

		case AST_DECL_VEC: 
			astMakeCode(n->sons[0],f);
			fprintf(f,"["); astMakeCode(n->sons[1],f); fprintf(f,"]");
			astMakeCode(n->sons[2],f);
			fprintf(f,":");
			astMakeCode(n->sons[3],f);
		break; 
		case AST_DECL_VEC_EMPTY: 
			astMakeCode(n->sons[0],f);
			fprintf(f,"["); astMakeCode(n->sons[1],f); fprintf(f,"]");
			astMakeCode(n->sons[2],f);
		break; 

		case AST_LST_VEC1: astMakeCode(n->sons[0],f);astMakeCode(n->sons[1],f);break; 
		case AST_LST_VEC2: astMakeCode(n->sons[0],f);;break; 

		case AST_LST_DECL: 
			astMakeCode(n->sons[0],f);
			fprintf(f,";\n");
			astMakeCode(n->sons[1],f);
		break;
		case AST_LST_FUNC: 
			astMakeCode(n->sons[0],f);
			fprintf(f,";\n");
			astMakeCode(n->sons[1],f);
		break;

		case AST_LSTEND_DECL:
			astMakeCode(n->sons[0],f);
			fprintf(f,";\n");
		break;

		case AST_LSTEND_FUNC: 
			astMakeCode(n->sons[0],f);
			fprintf(f,";\n");
		break;
		default: fprintf(f,"UNKNOWN DEFAULT");break;

	}



}

