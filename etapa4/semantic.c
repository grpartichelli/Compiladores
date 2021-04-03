int semantic_errors = 0;

#include "semantic.h"


int get_type_of_keyword(int kw){
	switch(kw){

		case AST_KW_INT: return DATATYPE_INT; break;
		case AST_KW_CHAR: return DATATYPE_CHAR; break;
		case AST_KW_BOOL:  return DATATYPE_BOOL; break;
		case AST_KW_POINTER: return DATATYPE_POINTER; break;
		default: printf("ERROR: Wrong type argument.\n");exit(5);break;
	}

}

void ast_decl_lit_check_set(ast *n, int kw){

	if(!n->symbol || !n->symbol->content)
		return;

	if(n->symbol->type != SYMBOL_IDENTIFIER){
		printf("ERROR: Identifier %s already declared.\n",n->symbol->content);
		semantic_errors++;
		return;
	}

	n->symbol->type = SYMBOL_VARIABLE;
	n->symbol->datatype = get_type_of_keyword(kw);

			

}


void check_and_set_declarations(ast* n){
	if(!n)
		return;

	switch(n->type){

		case AST_DECL_LIT:
			ast_decl_lit_check_set(n->sons[1], n->sons[0]->type);
		break;


	}

	for(int i =0;i<NUM_SONS; i++){
		check_and_set_declarations(n->sons[i]);
	}

}


int get_semantic_errors(){

	return semantic_errors;
}

