#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER


#include "hash.h"
#include "ast.h"

extern int semantic_errors;

void check_and_set_declarations(ast* n);
void check_undeclared();
int get_semantic_errors();

#endif