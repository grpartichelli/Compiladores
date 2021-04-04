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

int check_num_identifier(ast *n){
	return (n->symbol != 0 && (n->symbol->datatype == DATATYPE_INT || n->symbol->datatype == DATATYPE_CHAR  ) );
}
			

int operator_is_num(ast *n){

	return (n->type == AST_ADD ||
			n->type == AST_SUB ||
			n->type == AST_MULT ||
			n->type == AST_DIV ||
			n->type == AST_PARENTESIS  ||
			n->type == AST_SYMBOL_INT  ||
			n->type == AST_SYMBOL_CHAR ||
			check_num_identifier(n)    ||
			(n->type == AST_VECTOR && check_num_identifier(n->sons[0]))||
			(n->type == AST_EXPR_FUNCTION && check_num_identifier(n->sons[0])));
}

void check_types_num_op(ast *n1, ast *n2,char* op){

	if(n1 == 0 || n2 == 0){
		if(debug)
			printf("unexpected problem at check_types_num_op");
		return;
	}

	if(!operator_is_num(n1)){
		printf("ERROR: Left operand of %s is not a number.\n", op);
		semantic_errors++;
	}
	if(!operator_is_num(n2)){
		printf("ERROR: Right operand of %s is not a number.\n",op);
		semantic_errors++;
	}

}

int check_bool_identifier(ast *n){
	return (n->symbol != 0 && (n->symbol->datatype == DATATYPE_BOOL ));
}

int operator_is_bool(ast *n){

	return( n->type == AST_LESS ||
			n->type == AST_GREATER ||
			n->type == AST_LE||
			n->type == AST_GE ||
			n->type == AST_EQ ||
			n->type == AST_DIF ||
			n->type == AST_AND ||
			n->type == AST_OR ||
			n->type == AST_NEG ||
			n->type == AST_PARENTESIS  ||
			n->type == AST_SYMBOL_TRUE  ||
			n->type == AST_SYMBOL_FALSE ||
			check_bool_identifier(n)    ||
			(n->type == AST_VECTOR && check_bool_identifier(n->sons[0]))||
			(n->type == AST_EXPR_FUNCTION && check_bool_identifier(n->sons[0])));
}

void check_types_bool_op(ast *n1, ast *n2,char* op){

	if(n1 == 0 || n2 == 0){
		if(debug)
			printf("unexpected problem at check_types_num_op");
		return;
	}

	if(!operator_is_bool(n1)){
		printf("ERROR: Left operand of %s is not a boolean.\n", op);
		semantic_errors++;
	}
	if(!operator_is_bool(n2)){
		printf("ERROR: Right operand of %s is not a boolean.\n",op);
		semantic_errors++;
	}

}


void check_types_num_bool_op(ast *n1, ast *n2,char* op){

	if(n1 == 0 || n2 == 0){
		if(debug)
			printf("unexpected problem at check_types_num_op");
		return;
	}

	if( !( (operator_is_bool(n1) && operator_is_bool(n2)) || ((operator_is_num(n1) && operator_is_num(n2))) ) ){
		printf("ERROR: Invalid operands of %s.\n", op);
		semantic_errors++;
	}
	

}

int check_pointer_identifier(ast *n){
	return (n->symbol != 0 && (n->symbol->datatype == DATATYPE_POINTER ));
}

int operator_is_pointer(ast *n){

	return( check_pointer_identifier(n)    ||
			(n->type == AST_VECTOR && check_pointer_identifier(n->sons[0]))||
			(n->type == AST_EXPR_FUNCTION && check_pointer_identifier(n->sons[0])));
}

void check_types_pointer_op(ast *n, char* op){

	if(n == 0 ){
		if(debug)
			printf("unexpected problem at check_types_num_op");
		return;
	}

	if(!operator_is_pointer(n)){
		printf("ERROR: Invalid operands of %s.\n", op);
		semantic_errors++;
	}
	

}


void check_types(ast *n){

	if(!n)
		return;

	switch(n->type){
		case AST_ADD:
			check_types_num_op(n->sons[0],n->sons[1],"+");
		break;
		case AST_SUB:
			check_types_num_op(n->sons[0],n->sons[1],"-");
		break;
		case AST_DIV:
			check_types_num_op(n->sons[0],n->sons[1],"/");
		break;
		case AST_MULT:
			check_types_num_op(n->sons[0],n->sons[1],"*");
		break;
		case AST_LESS:
			check_types_num_op(n->sons[0],n->sons[1],"<");
		break;
		case AST_GREATER:
			check_types_num_op(n->sons[0],n->sons[1],">");
		break;

		case AST_LE:
			check_types_num_op(n->sons[0],n->sons[1],"<=");
		break;

		case AST_GE:
			check_types_num_op(n->sons[0],n->sons[1],">=");
		break;


		case AST_OR:
			check_types_bool_op(n->sons[0],n->sons[1],"|");
		break;

		case AST_AND:
			check_types_bool_op(n->sons[0],n->sons[1],"&");
		break;
		case AST_NEG:
			if(!operator_is_bool(n->sons[0])){
				printf("ERROR: Operand of ~ is not a boolean.\n");
				semantic_errors++;
			}
		break;

		case AST_EQ:
			check_types_num_bool_op(n->sons[0],n->sons[1],"==");
		break;

		case AST_DIF:
			check_types_num_bool_op(n->sons[0],n->sons[1], "!=");
		break;

		case AST_DOLLAR:
			check_types_pointer_op(n->sons[0],"$");
		break;

		case AST_HASHTAG:
			check_types_pointer_op(n->sons[0], "#");
		break;
	}

	for(int i =0;i<NUM_SONS; i++){
		check_types(n->sons[i]);
	}


}

int get_semantic_errors(){

	return semantic_errors;
}

