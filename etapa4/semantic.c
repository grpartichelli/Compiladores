int semantic_errors = 0;
int debug = 1;
#include "semantic.h"



int is_datatype_compatible(int dtype1, int dtype2){

	if(dtype1 == DATATYPE_POINTER || dtype1 == dtype2 || (dtype1 == DATATYPE_INT && dtype2 == DATATYPE_CHAR) || (dtype1 == DATATYPE_CHAR && dtype2 == DATATYPE_INT) )
		return 1;
	else
		return 0;
}

int get_symbol_type(int type_symbol){
	switch(type_symbol){

		case AST_SYMBOL_INT: return DATATYPE_INT; break;
		case AST_SYMBOL_CHAR: return DATATYPE_CHAR;break;
		case AST_SYMBOL_TRUE: return DATATYPE_BOOL;break;
		case AST_SYMBOL_FALSE: return DATATYPE_BOOL;break;
		default: 
			if(debug)
				printf("This is a bit unexpected on get_symbol_type\n");
			return -1;
		break;
	}
	return -1;

}


int get_type_of_keyword(int kw){
	switch(kw){

		case AST_KW_INT: return DATATYPE_INT; break;
		case AST_KW_CHAR: return DATATYPE_CHAR; break;
		case AST_KW_BOOL:  return DATATYPE_BOOL; break;
		case AST_KW_POINTER: return DATATYPE_POINTER; break;
		default:
			if(debug)
					printf("This is a bit unexpected on get_type_of_keyword\n");
			return -1;
		break;
	}

}

void ast_decl_lit_check_set(ast *n, int kw, int symbol){

	int type_symbol;

	if(!n->symbol || !n->symbol->content)
		return;

	if(n->symbol->type != SYMBOL_IDENTIFIER){
		printf("ERROR: Identifier %s already declared.\n",n->symbol->content);
		semantic_errors++;
	
	}
	else{

		n->symbol->type = SYMBOL_VARIABLE;
		n->symbol->datatype = get_type_of_keyword(kw);
		
		
		type_symbol=get_symbol_type(symbol);

		if(type_symbol == -1 || !is_datatype_compatible(n->symbol->datatype,type_symbol)){
			printf("ERROR: Identifier %s of type %d declared with wrong type %d.\n",
				n->symbol->content, n->symbol->datatype,type_symbol);
			semantic_errors++;
		}
	}
		

}
	

void ast_decl_vec_empty_check_set(ast *n, int kw){


	if(!n->symbol || !n->symbol->content)
		return;

	if(n->symbol->type != SYMBOL_IDENTIFIER){
		printf("ERROR: Identifier %s already declared.\n",n->symbol->content);
		semantic_errors++;
	
	}
	else{

		n->symbol->type = SYMBOL_VECTOR;
		n->symbol->datatype = get_type_of_keyword(kw);
		
	}
		

}

void ast_decl_vec_check_set(ast *n, int kw, ast *list){

	int type_symbol;
	ast *dec_node;

	if(!n->symbol || !n->symbol->content)
		return;

	if(n->symbol->type != SYMBOL_IDENTIFIER){
		printf("ERROR: Identifier %s already declared.\n",n->symbol->content);
		semantic_errors++;
	
	}
	else{

		n->symbol->type = SYMBOL_VECTOR;
		n->symbol->datatype = get_type_of_keyword(kw);

		dec_node = list;
		while(dec_node){
			
			type_symbol=get_symbol_type(dec_node->sons[0]->type);

			if(type_symbol == -1 || !is_datatype_compatible(n->symbol->datatype,type_symbol)){
				printf("ERROR: Identifier %s of type %d declared with wrong type %d.\n",
					n->symbol->content, n->symbol->datatype,type_symbol);
				semantic_errors++;
				return;
			}
			
			dec_node = dec_node->sons[1];


		}
		
	}
		

}


void ast_function_check_set(ast *n, int kw, ast *list){

	ast *par;

	if(!n->symbol || !n->symbol->content)
		return;

	if(n->symbol->type != SYMBOL_IDENTIFIER){
		printf("ERROR: Identifier %s already declared.\n",n->symbol->content);
		semantic_errors++;
	
	}
	else{

		n->symbol->type = SYMBOL_FUNCTION;
		n->symbol->datatype = get_type_of_keyword(kw);

		//Now the parameters
		par = list;
		while(par){
			
			kw = par->sons[0]->type;

			if(par->sons[1]->symbol->type != SYMBOL_IDENTIFIER){
				printf("ERROR: Identifier %s already declared.\n",par->sons[1]->symbol->content);
				semantic_errors++;
			}
			else{
				par->sons[1]->symbol->type = SYMBOL_VARIABLE;
				par->sons[1]->symbol->datatype = get_type_of_keyword(kw);
				
			}
			
			par = par->sons[2];


		}
		
		
	}	
		

}


			
void check_and_set_declarations(ast* n){
	if(!n)
		return;

	switch(n->type){

		case AST_DECL_LIT:
			ast_decl_lit_check_set(n->sons[1], n->sons[0]->type, n->sons[2]->type);
		break;
		case AST_DECL_VEC_EMPTY:
			ast_decl_vec_empty_check_set(n->sons[2],n->sons[0]->type);
		break;
		case AST_DECL_VEC:
			ast_decl_vec_check_set(n->sons[2],n->sons[0]->type, n->sons[3]);
		break;
		case AST_FUNCTION:
			ast_function_check_set(n->sons[1],n->sons[0]->type, n->sons[2]);
		break;


	}

	for(int i =0;i<NUM_SONS; i++){
		check_and_set_declarations(n->sons[i]);
	}

}

void check_undeclared(){
	semantic_errors +=hash_check_undeclared();
}

int get_semantic_errors(){

	return semantic_errors;
}

