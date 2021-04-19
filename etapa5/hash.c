//Código de Gabriel Rizzolli Partichelli - 301416

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
			printf("Hash Pos: %d - Valor: %s - Tipo %d - DataType %d\n",i,n->content,n->type,n->datatype);
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
node* putHash(int type,char *content){

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
	return n;
}



//Imprime a hash
int hash_check_undeclared(){
	node *n;
	int count = 0;
	for(int i=0;i<TABLE_SIZE;i++){
		for(n = hash_table[i]; n; n = n->next){
			if(n->type == SYMBOL_IDENTIFIER ){
				printf("ERROR: Identifier %s not declared.\n",n->content);
				count++;
			}
		}
	}
	return count;
}

node *makeTemp(void){

	static int serial  = 0;
	char buffer[256] = "";

	sprintf(buffer, "mYwEEird_temP%d",serial++);
	return putHash(SYMBOL_VARIABLE,buffer);

}



node *makeLabel(void){
	static int serial  = 0;
	char buffer[256] = "";

	sprintf(buffer, "mYwEEird_labeL%d",serial++);
	return putHash(SYMBOL_LABEL,buffer);

}