%{
	#include "tokens.h"
	int numLines=0;
	int running=1;
%}

%%

"char" {return KW_CHAR;}
"int" {return KW_INT; }
"bool" {return KW_BOOL;}
"pointer" {return KW_POINTER;}
"if" {return KW_IF; }
"then" {return KW_THEN;}
"else" {return KW_ELSE;}
"while" {return KW_WHILE; }
"read" {return KW_READ;}
"print" {return KW_PRINT;}
"return" {return KW_RETURN; }

[-,;:()\[\]\{\}+*\/<>|&~$#] {return yytext[0];}

[\t ]

"<=" {return OPERATOR_LE;}
">=" {return OPERATOR_GE;}
"==" {return OPERATOR_EQ;}
"!=" {return OPERATOR_DIF;}
"<-" {return LEFT_ASSIGN;}
"->" {return RIGHT_ASSIGN;}

. {return TOKEN_ERROR;}
%%

int yywrap(){	//Executado quando acaba o arquivo
	running=0;
	return 1;
}


//Funções a seguir são utilizadas na main
int isRunning(void){ 
	return running;
}

void initMe(void){
	return;
}



