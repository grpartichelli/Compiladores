%{
#include <stdio.h>
#include <stdlib.h>
int getLineNumber();
int yylex();
%}

%token KW_CHAR       
%token KW_INT        
%token KW_BOOL       
%token KW_POINTER    

%token KW_IF         
%token KW_THEN      
%token KW_ELSE       
%token KW_WHILE      
%token KW_READ       
%token KW_PRINT      
%token KW_RETURN     

%token OPERATOR_LE   
%token OPERATOR_GE   
%token OPERATOR_EQ   
%token OPERATOR_DIF  
%token LEFT_ASSIGN   
%token RIGHT_ASSIGN  
%token TK_IDENTIFIER 


%token LIT_INTEGER   
%token LIT_TRUE      
%token LIT_FALSE     
%token LIT_CHAR      
%token LIT_STRING    

%token TOKEN_ERROR   


%%

programa: 
	variable ';' programa 
	| function ';' programa 
	| variable ';'
	| function ';'
	;

variable: 
	type TK_IDENTIFIER '=' varlit
	| type '[' LIT_INTEGER ']' TK_IDENTIFIER  ':' varlit vector_value
	| type '[' LIT_INTEGER ']' TK_IDENTIFIER 
	;

type: 
	KW_BOOL
	|KW_CHAR
	|KW_INT 
	|KW_POINTER 
	;

varlit: 
	LIT_INTEGER 
	| LIT_TRUE
	| LIT_FALSE
	| LIT_CHAR 
	;

vector_value: 
	varlit vector_value
	| 
	;


function: 
	type TK_IDENTIFIER '(' parameters ')' command
	;


parameters: 
	listparameters
	|
	;

listparameters:
	type TK_IDENTIFIER ',' listparameters
	| type TK_IDENTIFIER
	;

command:
	'{' block '}'
	| simple
	;

block:
	command ';' block	
	| command ';'
	;

simple:	
	KW_READ TK_IDENTIFIER
	|KW_RETURN expr;
	| assign
	| KW_PRINT print
	| flow_control
	;

flow_control:
	KW_IF '(' expr ')' KW_THEN command
	| KW_IF '(' expr ')' KW_THEN command KW_ELSE command
	| KW_WHILE '(' expr ')' command

print: LIT_STRING
	| expr
	| LIT_STRING ',' print
	| expr ',' print

assign:
	TK_IDENTIFIER LEFT_ASSIGN expr
	| TK_IDENTIFIER '[' expr ']' LEFT_ASSIGN expr
	| expr RIGHT_ASSIGN TK_IDENTIFIER 
	| expr RIGHT_ASSIGN TK_IDENTIFIER '[' expr ']'
	;
expr:
	'(' expr ')'
	| TK_IDENTIFIER
	| TK_IDENTIFIER '[' expr ']'
	| LIT_INTEGER
	| LIT_CHAR
	| LIT_TRUE
	| LIT_FALSE
	| TK_IDENTIFIER '(' func_arguments ')'
	| '~' expr 
	| '$' expr
	| '#' expr
	| expr '+' expr
	| expr '-' expr 
	| expr '*' expr
	| expr '/' expr 
	| expr '<' expr 
	| expr '|' expr
	| expr '&' expr
	| expr OPERATOR_LE expr  
	| expr OPERATOR_GE expr   
	| expr OPERATOR_EQ expr   
	| expr OPERATOR_DIF expr  
	;
func_arguments:
	func_arguments_list
	| 
	;
func_arguments_list:
	expr ',' func_arguments_list
	| expr
	;


%%

int yyerror(){
	
	printf("Erro de sintaxe na linha %d\n",getLineNumber());
	exit(3);
}