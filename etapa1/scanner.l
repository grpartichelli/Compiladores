%{
	#include "tokens.h"
	int numLines=1;
	int running=1;
%}

%x MULTI_LINE_COMMENT

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

"true"	{return LIT_TRUE;}
"false"	{return LIT_FALSE;}

[-,;:()\[\]\{\}+*\/<>|&~$#] {return yytext[0];}

[ \t]

"<=" {return OPERATOR_LE;}
">=" {return OPERATOR_GE;}
"==" {return OPERATOR_EQ;}
"!=" {return OPERATOR_DIF;}
"<-" {return LEFT_ASSIGN;}
"->" {return RIGHT_ASSIGN;}

[a-zA-Z_][0-9a-zA-Z_]* {return TK_IDENTIFIER;}

[0-9]+ {return LIT_INTEGER;}
"'"."'" {return LIT_CHAR;}
\"(\\.|[^\\"])*\" {return LIT_STRING;}

"\n" {numLines++;}

"//".*

"/*" {BEGIN(MULTI_LINE_COMMENT);}
<MULTI_LINE_COMMENT>"*/" {BEGIN(INITIAL);}
<MULTI_LINE_COMMENT>"\n" {numLines++;}
<MULTI_LINE_COMMENT>. 


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

int getLineNumber(void){
	return numLines;
}

