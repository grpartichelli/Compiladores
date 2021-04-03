#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TIPOS
#define SYMBOL_IDENTIFIER 100
#define SYMBOL_LIT_INT 200
#define SYMBOL_LIT_CHAR 300
#define SYMBOL_LIT_STRING 400
#define SYMBOL_LIT_TRUE 500
#define SYMBOL_LIT_FALSE 600
#define SYMBOL_VARIABLE 700
#define SYMBOL_FUNCTION 800
#define SYMBOL_VECTOR 900

#define DATATYPE_INT 1000
#define DATATYPE_CHAR 1100
#define DATATYPE_BOOL 1200
#define DATATYPE_POINTER 1300



struct ast_node;

typedef struct node
{
	int type;
	int datatype;
	char *content;
	struct node *next;
	struct astnode* parameters;

} node;

void loadHash(); //Inicializaçao da hash
void printHash();//Imprime a tabela
node *getHash(char *content);//Procura por um nodo na tabela e retorna
node* putHash(int type, char *content);//Adiciona um nodo a tabela
int getAddress(char *content); //Devolve o endereço do nodo na hash


#endif