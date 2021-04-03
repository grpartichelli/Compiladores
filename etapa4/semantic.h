#ifndef SEMANTIC_HEADER
#define SEMANTIC_HEADER

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "ast.h"

extern int semantic_errors;

void check_and_set_declarations(ast* n);
void check_undeclared();
int get_semantic_errors();

int get_type_of_keyword(int kw);
void ast_decl_lit_check_set(ast *n, int kw);

#endif