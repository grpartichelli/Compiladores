

%{
	#include "tokens.h"
	#include "hash.h"
	int numLines=1;
	int running=1;
%}

%x MULTI_LINE_COMMENT

%%

"<p".*">".*"</p>"	{printf("%s",yytext);}


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
	loadHash();
	return;
}

int getLineNumber(void){
	return numLines;
}

