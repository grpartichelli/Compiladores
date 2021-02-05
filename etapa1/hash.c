#include "hash.h"

#define TABLE_SIZE 1511 //um número primo

node *hash_table[TABLE_SIZE];

//Inicializaçao da hash
void loadHash(){
	for(int i=0;i<TABLE_SIZE; i++){
		hash_table[i] = 0;
	}
}

//Imprime a hash
void printHash(){
	node *n;

	for(int i=0;i<TABLE_SIZE;i++){
		for(n = hash_table[i]; n; n = n->next){
			printf("Hash Pos: %d - Valor: %s\n",i,n->content);
		}
	}
}

//Busca a posição a se colocar certa string
int getAddress(char *content){
	int pos = 1;
	int str_size = strlen(content);
	for(int i=0;i<str_size;i++){
		pos = (pos * content[i]) % TABLE_SIZE + 1;
	}
	return --pos;
}
//Pega na hash o nodo com o conteudo dado
node *getHash(char *content){
	node *n;
	int pos = getAddress(content);
	for(n = hash_table[pos]; n; n = n->next){
		if (!strcmp(n->content,content)){
			return n;
		}
	}
	return NULL;
}
//Adiciona um novo nodo a hash
void putHash(int type,char *content){

	node *n;

	//Se o nodo já estiver na tabela não faz nada

	if(!(n = getHash(content))){
		//Inicializando novo nodo
		
		n = (node*) calloc(1,sizeof(node));
		n->content = (char*) calloc(strlen(content)+1,sizeof(char));
		
		n->type = type;
		strcpy(n->content,content);
		
		int pos = getAddress(content);
		n->next = hash_table[pos];
		hash_table[pos] = n;
	}
}