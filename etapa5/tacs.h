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

#define TAC_NEG 14
#define TAC_HASHTAG 15
#define TAC_DOLLAR 16

#define TAC_LABEL 17
#define TAC_JUMP 18
#define TAC_JUMP_IF_FALSE 19

#define TAC_COPY 20
#define TAC_COPY_VEC 21

#define TAC_DECL_VEC_EMPTY 22
#define TAC_DECL_VEC 23
#define TAC_DECL_VEC_ITEM 24

#define TAC_READ 25
#define TAC_RETURN 26
#define TAC_PRINT 27

#define TAC_VECTOR 28

#define TAC_FUNC_CALL 29
#define TAC_FUNC_CALL_ARG 30

#define TAC_FUNC_DECL 31
#define TAC_FUNC_DECL_ARG 32

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