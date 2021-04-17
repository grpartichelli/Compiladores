#ifndef GENCODE_HEADER
#define GENCODE_HEADER

#include "hash.h"
#include "ast.h"
#include "tacs.h"

tac* genCode(ast *n);

node* getRes(tac *t);

tac *genTacSymbol(ast *n);



#endif