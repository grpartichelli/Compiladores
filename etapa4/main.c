//Código de Gabriel Rizzolli Partichelli - 301416


#include <stdio.h>
#include <stdlib.h>

//Eu imagino que esses includes não devem gerar problemas na correção 
//pois não estão afetando a compilação:
#include "hash.h"
#include "ast.h"
#include "y.tab.h" 
#include "lex.yy.h"
#include "semantic.h"
//Essas funções estão no scanner.l:
int isRunning(void);
void initMe(void);
int getLineNumber(void);

//Essas funções estão no parser.y
void loadOutFile(FILE *saida);

//Essas funções estão no semantic.h
int get_semantic_errors();

int yyparse();
extern char *yytext;
extern FILE *yyin;


int main(int argc, char **argv){
	FILE *saida;

	if(argc != 3){
		printf("Número errado de argumentos, chame como ./etapa3 arquivo_de_entrada arquivo_de_saida\n");
		exit(1);
	}
	
	if(!(yyin = fopen(argv[1],"r"))){
		printf("Não foi possivel abrir o arquivo de entrada %s\n",argv[1]);
		exit(2);
	}

	//Arquivo de saida
	if(!(saida= fopen(argv[2],"w"))){
		printf("Não foi possivel abrir o arquivo de saida%s\n",argv[2]);
		exit(2);
	}


	loadOutFile(saida); //Carrega o arquivo de saida
	initMe(); //Inicialização da tabela hash

	yyparse();


	printf("Número de Linhas: %d\n",getLineNumber());
	printHash();


	if(get_semantic_errors()){
		printf("ERROR: Found %d semantic errors.\n",get_semantic_errors());
		exit(4);
	}

	printf("Compilação concluida com sucesso.\n");

	

	exit(0);
}