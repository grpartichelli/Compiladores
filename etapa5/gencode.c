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

tac *genUniOp(int tac_type, tac **code){
	return tacJoin(code[0], tacCreate(tac_type, makeTemp(), getRes(code[0]), 0));
}

tac *genBinOp(int tac_type, tac **code){
	return tacJoin(tacJoin(code[0],code[1]),tacCreate(tac_type,makeTemp(), getRes(code[0]), getRes(code[1])));
}


tac *genIfThen(tac **code){
	node *newlabel;
	tac *jump, *label;
	newlabel = makeLabel();

	jump = tacCreate(TAC_JUMP_IF_FALSE,newlabel,getRes(code[0]),0);
	jump->prev = code[0];

	label = tacCreate(TAC_LABEL,newlabel,0,0);
	label->prev = code[1];

	return tacJoin(jump,label);
}

tac *genIfThenElse(tac **code){

    node* labelElse, *labelEnd;
    labelElse = makeLabel();
    labelEnd = makeLabel();
  
    
    tac *tacJumpFalse= tacCreate(TAC_JUMP_IF_FALSE, labelElse, getRes(code[0]), 0);
    tac *tacJump = tacCreate(TAC_JUMP, labelEnd, 0, 0);

    tacJumpFalse->prev = code[0];
    tacJump->prev = code[1];

    tacJoin(tacJumpFalse, tacJump);


    tac *tacLabelEnd = tacCreate(TAC_LABEL,labelEnd, 0, 0);
    tac* tacLabelElse = tacCreate(TAC_LABEL, labelElse, 0, 0);

    tacLabelEnd->prev = code[2];
    tacLabelElse->prev = tacJump;

    return tacJoin(tacLabelElse,  tacLabelEnd);
}

tac* genWhile(tac **code){
	node* labelStart, *labelEnd;
	labelStart = makeLabel();
    labelEnd = makeLabel();

    tac *tacEnd= tacCreate(TAC_LABEL, labelEnd ,0, 0);
    tac *tacJumpFalse = tacCreate(TAC_JUMP_IF_FALSE, labelEnd, getRes(code[0]), 0);

    tac *tacStart = tacCreate(TAC_LABEL, labelStart,  0, 0);
    tac *tacJump = tacCreate(TAC_JUMP, labelStart, 0, 0);

 
    tac *t1 = tacJoin(tacStart, code[0]);
    tac *t2 = tacJoin(t1, tacJumpFalse);
    tac *t3 = tacJoin(t2, code[1]);
    tac *t4 = tacJoin(t3, tacJump);
    return tacJoin(t4, tacEnd);


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

		//SIMBOLOS
		case AST_SYMBOL_INT: result = genTacSymbol(n); break;
		case AST_SYMBOL_CHAR: result = genTacSymbol(n); break;
		case AST_SYMBOL_TRUE: result = genTacSymbol(n); break;
		case AST_SYMBOL_FALSE: result = genTacSymbol(n); break;
		case AST_SYMBOL_IDENTIFIER: result = genTacSymbol(n); break;
		case AST_SYMBOL_STRING: result = genTacSymbol(n); break;

		//OP BINARIAS
		case AST_ADD: 			result = genBinOp(TAC_ADD,code);break;
		case AST_SUB: 			result = genBinOp(TAC_SUB,code);break;
		case AST_MULT: 			result = genBinOp(TAC_MULT,code);break;
		case AST_DIV:			result = genBinOp(TAC_DIV,code);break;
		case AST_LESS:		 	result = genBinOp(TAC_LESS,code);break;
		case AST_GREATER: 		result = genBinOp(TAC_GREATER,code);break;
		case AST_OR:		    result = genBinOp(TAC_OR,code);break;
		case AST_AND:			result = genBinOp(TAC_AND,code);break;
		case AST_LE:		 	result = genBinOp(TAC_LE,code);break;
		case AST_GE:		 	result = genBinOp(TAC_GE,code);break;
		case AST_EQ:		 	result = genBinOp(TAC_EQ,code);break;
		case AST_DIF:		 	result = genBinOp(TAC_DIF,code);break;

		//OP UNITARIA
		case AST_NEG: 			result = genUniOp(TAC_NEG,code);break;
		case AST_DOLLAR: 		result = genUniOp(TAC_DOLLAR,code);break;
		case AST_HASHTAG: 		result = genUniOp(TAC_HASHTAG,code);break;

		//COMANDOS
		case AST_READ: result = tacJoin(code[0],tacCreate(TAC_READ,getRes(code[0]),0,0));
		break;

		case AST_RETURN: result = tacJoin(code[0],tacCreate(TAC_RETURN,getRes(code[0]),0,0));
		break;

		case AST_PRINT: 
		case AST_PRINTLST_STRING:
		case AST_PRINTLST_EXPR:
			result = tacJoin(tacJoin(code[0],tacCreate(TAC_PRINT,getRes(code[0]),0,0) ), code[1]);
		break;

		//CONTROLE DE FLUXO
		case AST_IF: result = genIfThen(code);break;
		case AST_IFELSE: result = genIfThenElse(code);break;
		case AST_WHILE: result = genWhile(code);break;


		//ASSINALAMENTO
		case AST_LEFT_ASSIGN:  result = tacJoin(code[0],tacJoin(code[1], tacCreate(TAC_COPY, getRes(code[0]),  getRes(code[1]), 0)));
		break;
        case AST_RIGHT_ASSIGN: result = tacJoin(code[0],tacJoin(code[1], tacCreate(TAC_COPY, getRes(code[1]),  getRes(code[0]), 0)));
    	break;

    	//ASSINALAMENTO COM VETOR /TAC_COPY_VEC(destino, index, origem)
    	case AST_LEFT_ASSIGN_VEC:  result = tacJoin(code[0],tacJoin(code[1], tacJoin(code[2] ,tacCreate(TAC_COPY_VEC,getRes(code[0]), getRes(code[1]), getRes(code[2])))));
    	break;
    	case AST_RIGHT_ASSIGN_VEC:  result = tacJoin(code[0],tacJoin(code[1], tacJoin(code[2] ,tacCreate(TAC_COPY_VEC, getRes(code[1]), getRes(code[2]),getRes(code[0])))));
    	break;
    	
   		//DECLARA VARIAVEL
   		case AST_DECL_LIT: result = tacJoin(code[1],tacJoin(code[2], tacCreate(TAC_COPY, getRes(code[1]),  getRes(code[2]), 0)));
   		break;
   		//DECLARA VETOR
   		//TAC_DECL_VEC_EMPTY(nome,tamanho)
   		case AST_DECL_VEC_EMPTY:  result = tacJoin(code[2],tacJoin(code[1], tacCreate(TAC_DECL_VEC_EMPTY, getRes(code[2]),  getRes(code[1]), 0)));
   	    break;

   	    //TAC_DECL_VEC(nome,tamanho)
   	    case AST_DECL_VEC:  result = tacJoin(tacJoin(code[2],tacJoin(code[1], tacCreate(TAC_DECL_VEC, getRes(code[2]),  getRes(code[1]), 0))), code[3]);
   	    break;
   	    case AST_LST_VEC1:
   	    case AST_LST_VEC2:
   	    	result = tacJoin(tacCreate(TAC_DECL_VEC_ITEM,getRes(code[0]),0,0), code[1]);
   	    break;

   	    //VECTOR SENDO ACESSADO(destino,nome,indice)
   	    case AST_VECTOR:
   	    	result = tacJoin(tacJoin(code[0],code[1]),tacCreate(TAC_VECTOR,makeTemp(), getRes(code[0]), getRes(code[1]))); 
   	    break;

   	    //FUNÇÃO SENDO CHAMADA
   	    
   	    case AST_EXPR_FUNCTION:
   	    	if(code[1] && code[1]->type != TAC_FUNC_CALL_ARG)
   	    		result = tacJoin(code[0],tacJoin(tacCreate(TAC_FUNC_CALL_ARG, getRes(code[1]), 0, 0), tacCreate(TAC_FUNC_CALL,  makeTemp(), getRes(code[0]), 0)));
   	    	else
   	    		result = tacJoin(code[0],tacJoin(code[1], tacCreate(TAC_FUNC_CALL,  makeTemp(), getRes(code[0]), 0)));

   	    		
   	    break;
   	    case AST_FUNC_ARGUMENTS:
   	    	if(code[1] && code[1]->type != TAC_FUNC_CALL_ARG)
   	    		result = tacJoin(tacCreate(TAC_FUNC_CALL_ARG, getRes(code[0]), 0, 0), tacCreate(TAC_FUNC_CALL_ARG, getRes(code[1]), 0, 0));
   	    	else
   	    		result = tacJoin(tacCreate(TAC_FUNC_CALL_ARG, getRes(code[0]), 0, 0),code[1]);
   	    		
   	    break;
	
   	    //FUNÇÃO DECLARADA
   	    case AST_FUNCTION:
   	    	result = tacJoin(tacJoin(tacJoin(code[1], tacCreate(TAC_FUNC_DECL,getRes(code[1]),0,0)),code[2]),code[3]);
   	    break; 
   	    case AST_LST_PAR:
   	    case AST_LST_PAREND:
   	    	result = tacJoin(tacJoin(code[1],tacCreate(TAC_FUNC_DECL_ARG,getRes(code[1]),0,0)), code[2]);
   	    break;

		default: result = tacJoin(code[0],tacJoin(code[1],tacJoin(code[2],code[3])));
   	    }

	

	return result;

}
