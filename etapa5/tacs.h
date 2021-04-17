#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include "ast.h"


#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_SUB 3

typedef struct tac{
	int type;
	node *res;
	node *op1;
	node *op2;
	struct tac *prev;
	struct tac *next;
} tac;

tac *tacCreate(int type, node *res,node *op1,node *op2);
void tacPrint(tac *t);
void tacPrintReverse(tac *t);
tac* tacJoin(tac* t1, tac* t2);


#endif