#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TIPOS
#define SYMBOL_LIT_INT 1
#define SYMBOL_LIT_CHAR 2
#define SYMBOL_LIT_STRING 3
#define SYMBOL_IDENTIFIER 4

typedef struct node
{
	int type;
	char *content;
	struct node *next;
} node;

void loadHash(); //Inicializaçao da hash
void printHash();//Imprime a tabela
node *getHash(char *content);//Procura por um nodo na tabela e retorna
node* putHash(int type, char *content);//Adiciona um nodo a tabela
int getAddress(char *content); //Devolve o endereço do nodo na hash


#endif