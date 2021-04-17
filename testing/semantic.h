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
void ast_decl_lit_check_set(ast *n, int kw, int symbol);
int is_datatype_compatible(int dtype1, int dtype2);
int get_symbol_type(int type_symbol);

void ast_decl_vec_empty_check_set(ast *n, int kw);
void ast_decl_vec_check_set(ast *n, int kw, ast *list);

void ast_function_check_set(ast *n, int kw, ast*list);

void check_types(ast *n);

int check_num_identifier(ast *n);
int operator_is_num(ast *n);
void check_types_num_op(ast *n1, ast *n2,char* op);

int check_bool_identifier(ast *n);
int operator_is_bool(ast *n);
void check_types_bool_op(ast *n1, ast *n2,char* op);

void check_types_num_bool_op(ast *n1, ast *n2,char* op);

int check_pointer_identifier(ast *n);
int operator_is_pointer(ast *n);
void check_types_pointer_op(ast *n, char* op);
int check_for_pointer(ast *n);

int compare_types(ast* a, ast*b);
int check_func_pars(ast* list1, ast* list2);

#endif