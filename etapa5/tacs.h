#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include "ast.h"


#define TAC_SYMBOL 1

typedef struct tac{
	int type;
	node *res;
	node *op1;
	node *op2;
	struct tac *prev;
	struct tac *next;
} tac;

tac *tacCreate(int type, node *res,node *op1,node *op2);
void tacPrint(tac *tac);
void tacPrintReverse(tac *tac);

//GEN CODE
tac* genCode(ast *node);

#endif