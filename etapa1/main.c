#include <stdio.h>
#include <stdlib.h>

//Eu imagino que esses includes não devem gerar problemas na correção p
//pois não estão afetando a compilação:
#include "tokens.h" 
#include "hash.h"

//Essas funções estão no scanner.l:
int isRunning(void);
void initMe(void);
int getLineNumber(void);

//Importando algumas funções do lex.yy.h, que é gerado usamos "lex scanner.l"
int yylex();  
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


	int token;
	initMe(); //Inicialização da tabela hash

	while(isRunning()){

		token = yylex();
		
		if(isRunning()){ //Testa novamente pois é possivel que tenha sido o end of file
			printf("Linha: %d - ", getLineNumber());
			switch(token){
				//Palavras Reservadas:
				case KW_CHAR:{printf("Palavra Reservada: char\n");break;}
				case KW_INT:{printf("Palavra Reservada: int\n");break;}
				case KW_BOOL:{printf("Palavra Reservada: bool\n");break;}
				case KW_POINTER:{printf("Palavra Reservada: pointer\n");break;}
				case KW_IF:{printf("Palavra Reservada: if\n");break;}
				case KW_THEN:{printf("Palavra Reservada: then\n");break;}
				case KW_ELSE:{printf("Palavra Reservada: else\n");break;}
				case KW_WHILE:{printf("Palavra Reservada: while\n");break;}
				case KW_READ:{printf("Palavra Reservada: read\n");break;}
				case KW_PRINT:{printf("Palavra Reservada: print\n");break;}
				case KW_RETURN:{printf("Palavra Reservada: return\n");break;}

				//Caracteres Especiais
				case 44:{printf("Caracter Especial: ,\n");break;}
				case 59:{printf("Caracter Especial: ;\n");break;}
				case 58:{printf("Caracter Especial: :\n");break;}
				case 40:{printf("Caracter Especial: (\n");break;}
				case 41:{printf("Caracter Especial: )\n");break;}
				case 91:{printf("Caracter Especial: [\n");break;}
				case 93:{printf("Caracter Especial: ]\n");break;}
				case 123:{printf("Caracter Especial: {\n");break;}
				case 125:{printf("Caracter Especial: }\n");break;}
				case 43:{printf("Caracter Especial: +\n");break;}
				case 45:{printf("Caracter Especial: -\n");break;}
				case 42:{printf("Caracter Especial: *\n");break;}
				case 47:{printf("Caracter Especial: /\n");break;}
				case 60:{printf("Caracter Especial: <\n");break;}
				case 62:{printf("Caracter Especial: >\n");break;}
				case 124:{printf("Caracter Especial: |\n");break;}
				case 38:{printf("Caracter Especial: &\n");break;}
				case 126:{printf("Caracter Especial: ~\n");break;}
				case 36:{printf("Caracter Especial: $\n");break;}
				case 35:{printf("Caracter Especial: #\n");break;}
				
				//Operadores Compostos
				case OPERATOR_LE:{printf("Operador Composto: <=\n");break;}
				case OPERATOR_GE:{printf("Operador Composto: >=\n");break;}
				case OPERATOR_EQ:{printf("Operador Composto: ==\n");break;}
				case OPERATOR_DIF:{printf("Operador Composto: !=\n");break;}
				case LEFT_ASSIGN:{printf("Operador Composto: <-\n");break;}
				case RIGHT_ASSIGN:{printf("Operador Composto: ->\n");break;}

				//Identificador
				case TK_IDENTIFIER:{printf("Identificador: %s\n",yytext);break;}

				//Literais
				case LIT_INTEGER:{printf("Literal Inteiro: %s\n",yytext);break;}
				case LIT_CHAR:{printf("Literal Char: %s\n",yytext);break;}
				case LIT_STRING:{printf("Literal String: %s\n",yytext);break;}
				case LIT_TRUE:{printf("Literal True: true\n");break;}
				case LIT_FALSE:{printf("Literal False: false\n");break;}

				//Error
				case TOKEN_ERROR:{printf("ERRO - Token Inesperado: %c\n",yytext[0]);break;}
				default:{printf("Case Default Foi Encontrado: %s\n",yytext);}
			}
		}
	}

	printf("Número de Linhas: %d\n",getLineNumber());
	printHash();

	exit(0);
}