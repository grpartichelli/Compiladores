int semantic_errors = 0;
int debug = 0;
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
		n->symbol->parameters = list;
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


	return (
			n->type == AST_ADD ||
			n->type == AST_SUB ||
			n->type == AST_MULT ||
			n->type == AST_DIV ||
			n->type == AST_PARENTESIS  ||
			n->type == AST_SYMBOL_INT  ||
			n->type == AST_SYMBOL_CHAR ||
			check_num_identifier(n)    ||
			(n->type == AST_VECTOR && check_num_identifier(n->sons[0]))||
			(n->type == AST_EXPR_FUNCTION && check_num_identifier(n->sons[0])) ||
			(n->type == AST_HASHTAG && operator_is_pointer(n->sons[0]))
			);
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



int operator_is_identifier(ast *n){
	
	
	if(n==0){
		return 0;
	}

	if(n->type == AST_SYMBOL_IDENTIFIER){	
		return 1;
	}
	else{
		return operator_is_identifier(n->sons[0]);
	}
	
							 
}

int num_pointers = 0;
void check_sub_add(ast *n){

	if(n == 0 ){
		return;
	}

	if(n->type == AST_ADD || n->type == AST_SUB){
		check_sub_add(n->sons[0]);
		check_sub_add(n->sons[1]); 
		check_sub_add(n->sons[2]);
		check_sub_add(n->sons[3]);	
		return;	
	} else if( operator_is_pointer(n)){
		num_pointers++;
		return;
	} 

	if(n->type != AST_SYMBOL_INT && n->type != AST_SYMBOL_CHAR)
		num_pointers -= 1000;


}

int check_pointer_identifier(ast *n){
	
	return (n->symbol != 0 && n->symbol->datatype == DATATYPE_POINTER
		);
}

int operator_is_pointer(ast *n){

	int pointer_check = 0;
	if(n->type == AST_ADD || n->type == AST_SUB){
		num_pointers=0;
		check_sub_add(n);
		pointer_check = num_pointers == 1;
		
	}

	int dollar_check = 0;
	if(n->type == AST_DOLLAR){
		dollar_check = operator_is_identifier(n->sons[0]);
	}

	return( 	check_pointer_identifier(n)    ||
			(n->type == AST_VECTOR && check_pointer_identifier(n->sons[0]))||
			(n->type == AST_EXPR_FUNCTION && check_pointer_identifier(n->sons[0])) ||
			dollar_check ||
			pointer_check 
			);
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


void check_types_add_sub_op(ast *n1, ast *n2,char* op){

	if(n1 == 0 || n2 == 0){
		if(debug)
			printf("unexpected problem at check_types_num_op");
		return;
	}


	if(!operator_is_pointer(n1) && !operator_is_pointer(n2)){
		if(!operator_is_num(n1)){
			printf("ERROR: Left operand of %s is not a number.\n", op);
			semantic_errors++;
		}
		if(!operator_is_num(n2)){
			printf("ERROR: Right operand of %s is not a number.\n",op);
			semantic_errors++;
		}
	}

}

int compare_types(ast* a, ast*b){


	return (operator_is_num(a) && operator_is_num(b)) ||
	   (operator_is_bool(a) && operator_is_bool(b)) ||
	   (operator_is_pointer(a) && operator_is_pointer(b));
}
int check_func_pars(ast* list1, ast* list2){

	if(list1 == 0 && list2 == 0){
		return 1;
	}
	
	if(list1 == 0 || list2 == 0){

		return 0;

	}


	if(list2->type != AST_FUNC_ARGUMENTS){
		
		if(compare_types(list1->sons[1],list2)){
			return 1 && check_func_pars(list1->sons[2], 0);
		} 	

	}else{
		if(compare_types(list1->sons[1], list2->sons[0])){
			return 1 && check_func_pars(list1->sons[2], list2->sons[1]);
		} 	
	}
	return 0;
	
}

void check_returns(ast *n, int type){
	
	if(n==0)
		return;
	
	if(n->type == AST_RETURN){
		switch(type){
			case DATATYPE_INT:
				if(!operator_is_num(n->sons[0])){
					printf("Function has invalid return, should be number.\n");
					semantic_errors++;
				}
			break;
			case DATATYPE_CHAR:
				if(!operator_is_num(n->sons[0])){
					printf("Function has invalid return, should be number.\n");
					semantic_errors++;
				}
			break;
			case DATATYPE_POINTER:
				if(!operator_is_pointer(n->sons[0])){
					printf("Function has invalid return, should be pointer.\n");
					semantic_errors++;
				}
			break;
			case DATATYPE_BOOL:
				if(!operator_is_bool(n->sons[0])){
					printf("Function has invalid return, should be bool.\n");
					semantic_errors++;
				}
			break;
		}

	} else{
		for(int i=0;i<NUM_SONS;i++){

			check_returns(n->sons[i],type);
		}

	}

	return;
	
}

void check_types(ast *n){

	if(!n)
		return;

	switch(n->type){
		case AST_FUNCTION:
			check_returns(n->sons[3],n->sons[1]->symbol->datatype);
		break;
		case AST_ADD:
			check_types_add_sub_op(n->sons[0],n->sons[1],"+");
		break;
		case AST_SUB:
			check_types_add_sub_op(n->sons[0],n->sons[1],"-");
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

		case AST_VECTOR:
			if(!operator_is_num(n->sons[1])){
				printf("ERROR: Vector index is not a number.\n");
				semantic_errors++;
			}
		break;

		case AST_EXPR_FUNCTION:
			if(!check_func_pars(n->sons[0]->symbol->parameters, n->sons[1])){
				printf("ERROR: Function call %s() has wrong parameters.\n",n->sons[0]->symbol->content);
				semantic_errors++;
			}
		break;		
		case  AST_IF:
			if(!operator_is_bool(n->sons[0])){
					printf("ERROR: If doesn't have a boolean.\n");
					semantic_errors++;
				}
		break;
		case  AST_IFELSE:
			if(!operator_is_bool(n->sons[0])){
					printf("ERROR: If Else doesnt have a boolean.\n");
					semantic_errors++;
				}
		break;

		case  AST_WHILE:
			if(!operator_is_bool(n->sons[0])){
					printf("ERROR: While doesnt have a boolean.\n");
					semantic_errors++;
				}
		break;

		case AST_LEFT_ASSIGN:
			if(!compare_types(n->sons[0],n->sons[1])){
				printf("ERROR: Left assign has different types.\n");
					semantic_errors++;
			}	
		break;
		case AST_RIGHT_ASSIGN:
			if(!compare_types(n->sons[0],n->sons[1])){
				printf("ERROR: Right assign has different types.\n");
					semantic_errors++;
			}	
		break;
		
		case AST_LEFT_ASSIGN_VEC:
			if(!compare_types(n->sons[0],n->sons[2])){
				printf("ERROR: Vector left assign has different types.\n");
					semantic_errors++;
			}

			if(operator_is_num(n->sons[1])){
				printf("ERROR: Vector left assign has non-number index.\n");
					semantic_errors++;
			}

		break;
		case AST_RIGHT_ASSIGN_VEC:

			if(!compare_types(n->sons[0],n->sons[1])){
					printf("ERROR: Vector right assign has different types.\n");
						semantic_errors++;
				}

				if(operator_is_num(n->sons[2])){
					printf("ERROR: Vector right assign has non-number index.\n");
						semantic_errors++;
				}

		break;

		case AST_RETURN:

		break;
		
	}

	for(int i =0;i<NUM_SONS; i++){
		check_types(n->sons[i]);
	}


}

int get_semantic_errors(){

	return semantic_errors;
}

