#include <stdio.h>
#include <stdlib.h>

#include "tokens.h" //Esse include não deve gerar problemas na correção pois não é necessário para a compilação dos outros arquivos

//Essas funções estão no scanner.l:
int isRunning(void);
void initMe(void);

//Importando algumas funções do lex.yy.h, que é gerado usamos "lex scanner.l"
int yylex();  
extern char *yytext;
extern FILE *yyin;


int main(){

	int token;
	initMe(); //Inicialização da tabela hash

	while(isRunning()){

		token = yylex();
		
		if(isRunning()){ //Testa novamente pois é possivel que tenha sido o end of file
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


				case TOKEN_ERROR:{printf("ERRO - Token Inesperado: %c\n",yytext[0]);break;}
				default:{printf("Caso Default - Foi Encontrado: %c\n",yytext[0]);}
			}
		}
	}


	exit(0);
}