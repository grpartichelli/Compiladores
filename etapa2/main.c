//Código de Gabriel Rizzolli Partichelli - 301416


#include <stdio.h>
#include <stdlib.h>

//Eu imagino que esses includes não devem gerar problemas na correção p
//pois não estão afetando a compilação:
#include "y.tab.h" 
#include "hash.h"
#include "lex.yy.h"

//Essas funções estão no scanner.l:
int isRunning(void);
void initMe(void);
int getLineNumber(void);

int yyparse();
extern char *yytext;
extern FILE *yyin;


int main(int argc, char **argv){

	if(argc != 2){
		printf("Número errado de argumentos, chame como ./etapa1 arquivo_de_entrada\n");
		exit(1);
	}
	
	if(!(yyin = fopen(argv[1],"r"))){
		printf("Não foi possivel abrir o arquivo de entrada %s\n",argv[1]);
		exit(1);
	}



	initMe(); //Inicialização da tabela hash

	yyparse();


	printf("Número de Linhas: %d\n",getLineNumber());
	printHash();

	printf("Compilação concluida com sucesso.\n");

	exit(0);
}