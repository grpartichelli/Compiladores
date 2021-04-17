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
		case TAC_SYMBOL: printf("TAC_SYMBOL");break;
		case TAC_ADD: printf("TAC_ADD"); break;
		case TAC_SUB: printf("TAC_SUB"); break;
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

