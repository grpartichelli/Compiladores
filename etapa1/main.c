#include <stdio.h>
#include <stdlib.h>

int yylex();  //lex.yy.h, evita que o compilador avise que essa função não foi declarada



int main(){

	yylex();


	return 1;
}