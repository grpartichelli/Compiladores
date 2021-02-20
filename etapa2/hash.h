#ifndef HASH_HEADER
#define HASH_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	int type;
	char *content;
	struct node *next;
} node;

void loadHash(); //Inicializaçao da hash
void printHash();//Imprime a tabela
node *getHash(char *content);//Procura por um nodo na tabela e retorna
void putHash(int type, char *content);//Adiciona um nodo a tabela
int getAddress(char *content); //Devolve o endereço do nodo na hash


#endif