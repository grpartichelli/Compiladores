#include "gencode.h"


node* getRes(tac *t){
	if(t){
		return t->res;
	}
	return 0;
}


tac *genTacSymbol(ast *n){
	return tacCreate(TAC_SYMBOL,n->symbol,0,0);
}


tac *genBinOp(int tac_type, tac **code){
	return tacJoin(tacJoin(code[0],code[1]),tacCreate(tac_type,makeTemp(), getRes(code[0]), getRes(code[1])));
}

tac* genCode(ast *n){

	if(!n)
		return 0;

	tac *result =0;
	tac *code[NUM_SONS];

	for(int i=0;i<NUM_SONS;i++){

		code[i] = genCode(n->sons[i]);
	}


	switch(n->type){	
		case AST_SYMBOL_INT: result = genTacSymbol(n); break;
		case AST_SYMBOL_CHAR: result = genTacSymbol(n); break;
		case AST_SYMBOL_TRUE: result = genTacSymbol(n); break;
		case AST_SYMBOL_FALSE: result = genTacSymbol(n); break;
		case AST_SYMBOL_IDENTIFIER: result = genTacSymbol(n); break;
		case AST_SYMBOL_STRING: result = genTacSymbol(n); break;
		case AST_ADD: 
			result = genBinOp(TAC_ADD,code);
		break;
		default: result = tacJoin(code[0],tacJoin(code[1],tacJoin(code[2],code[3])));

	}

	return result;

}
