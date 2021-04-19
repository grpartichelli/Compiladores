#include "tacs.h"



tac *tacCreate(int type, node *res,node *op1,node *op2){

	tac *t = 0;
	t = (tac *) calloc(1,sizeof(tac));
	t->type = type;
	t->res = res;
	t->op1 = op1;
	t->op2 =op2;
	t->prev = 0;
	t->next = 0;

	return t;
}

void tacPrint(tac *t){
	if(!t)
		return;

	printf("TAC(");

	switch(t->type){
		case TAC_SYMBOL: 		printf("TAC_SYMBOL");break;
		case TAC_ADD: 			printf("TAC_ADD"); break;
		case TAC_SUB: 			printf("TAC_SUB"); break;
		case TAC_MULT: 			printf("TAC_MULT");break;
		case TAC_DIV:			printf("TAC_DIV");break;
		case TAC_LESS:		 	printf("TAC_LESS");break;
		case TAC_GREATER: 		printf("TAC_GREATER");break;
		case TAC_OR:		    printf("TAC_OR");break;
		case TAC_AND:			printf("TAC_AND");break;
		case TAC_LE:		 	printf("TAC_LE");break;
		case TAC_GE:		 	printf("TAC_GE");break;
		case TAC_EQ:		 	printf("TAC_EQ");break;
		case TAC_DIF:		 	printf("TAC_DIF");break;

		case TAC_NEG: 			printf("TAC_NEG");break;
		case TAC_DOLLAR: 		printf("TAC_DOLLAR");break;
		case TAC_HASHTAG: 		printf("TAC_HASHTAG");break;

		case TAC_LABEL: 		printf("TAC_LABEL");break;
		case TAC_JUMP: 		    printf("TAC_JUMP");break;
		case TAC_JUMP_IF_FALSE: printf("TAC_JUMP_IF_FALSE");break;

		default: printf("UNKOWN_TAC");break;
	}
	
	printf(",%s",(t->res)? t->res->content:"0");
	printf(",%s",(t->op1)? t->op1->content:"0");
	printf(",%s",(t->op2)? t->op2->content:"0");
	printf(");\n");
}

void tacPrintReverse(tac *t){
	if(t){
		tacPrintReverse(t->prev);
		tacPrint(t);
	}
}

tac* tacJoin(tac* t1, tac* t2){
	tac *t;

	if(!t1) return t2;
	if(!t2) return t1;

	for(t = t2; t->prev != 0; t = t->prev);

	t->prev = t1;
	return t2;
}

