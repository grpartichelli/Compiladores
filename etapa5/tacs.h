#ifndef TACS_HEADER
#define TACS_HEADER

#include "hash.h"
#include "ast.h"


#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_MULT 4
#define TAC_DIV 5
#define TAC_LESS 6
#define TAC_GREATER 7
#define TAC_OR 8
#define TAC_AND 9
#define TAC_LE 10
#define TAC_GE 11
#define TAC_EQ 12
#define TAC_DIF 13


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