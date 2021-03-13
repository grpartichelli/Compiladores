%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "hash.h"
int getLineNumber();
int yylex();
FILE* outfile;
%}

%union{
	node *symbol;
	ast *ast;
}

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
%type<symbol> TK_IDENTIFIER


%token LIT_INTEGER  
%type<symbol> LIT_INTEGER 
%token LIT_TRUE      
%type<symbol> LIT_TRUE  
%token LIT_FALSE    
%type<symbol> LIT_FALSE  
%token LIT_CHAR 
%type<symbol> LIT_CHAR      
%token LIT_STRING 
%type<symbol> LIT_STRING  

%token TOKEN_ERROR  


%left '|' '&' 
%left '<' '>' OPERATOR_EQ OPERATOR_LE OPERATOR_GE OPERATOR_DIF
%left '+' '-'
%left '*' '/'  
%left '#' '$' '~'



%type<ast> expr
%type<ast> func_arguments
%type<ast> func_arguments_list
%type<ast> int
%type<ast> string
%type<ast> varlit
%type<ast> identifier

%%

inicio: programa
		;

programa: 
	decl ';' programa 
	| function ';' programa 
	| decl ';'
	| function ';'
	;

decl: 
	type identifier ':' varlit
	| type '[' int ']' identifier  ':' varlit vector_value
	| type '[' int']' identifier 
	;

type: 
	KW_BOOL
	|KW_CHAR
	|KW_INT 
	|KW_POINTER 
	;


vector_value: 
	varlit vector_value
	| 
	;


function: 
	type identifier '(' parameters ')' command
	;


parameters: 
	listparameters
	|
	;

listparameters:
	type identifier ',' listparameters
	| type identifier
	;

command:
	'{' block '}'
	| KW_READ identifier
	| KW_RETURN expr;
	| assign
	| KW_PRINT print
	| KW_IF '(' expr ')' KW_THEN command
	| KW_IF '(' expr ')' KW_THEN command KW_ELSE command
	| KW_WHILE '(' expr ')' command
	|
	;

block:
	command ';' block	
	| 
	;

print: string
	| expr
	| string ',' print
	| expr ',' print


assign:
	identifier LEFT_ASSIGN expr {astPrint($3,0);}
	| identifier '[' expr ']' LEFT_ASSIGN expr
	| expr RIGHT_ASSIGN identifier 
	| expr RIGHT_ASSIGN identifier '[' expr ']'
	;
expr:
	'(' expr ')' { $$ = astGenerate(AST_PARENTESIS,0,$2,0,0,0);}
	| identifier { $$ = $1;}
	| identifier '[' expr ']' { $$ = astGenerate(AST_VECTOR,0,$1,$3,0,0);}
	| varlit {$$ = $1;}
	| identifier '(' func_arguments ')' { $$ = astGenerate(AST_FUNCTION,0,$1,$3,0,0);}
	| '~' expr { $$ = astGenerate(AST_NEG,0,$2,0,0,0);}
	| '$' expr { $$ = astGenerate(AST_DOLLAR,0,$2,0,0,0);}
	| '#' expr { $$ = astGenerate(AST_HASHTAG,0,$2,0,0,0);}
	| expr '+' expr {$$ = astGenerate(AST_ADD,0,$1,$3,0,0);}
	| expr '-' expr {$$ = astGenerate(AST_SUB,0,$1,$3,0,0);}
	| expr '*' expr {$$ = astGenerate(AST_MULT,0,$1,$3,0,0);}
	| expr '/' expr {$$ = astGenerate(AST_DIV,0,$1,$3,0,0);}
	| expr '<' expr {$$ = astGenerate(AST_LESS,0,$1,$3,0,0);}
	| expr '>' expr {$$ = astGenerate(AST_GREATER,0,$1,$3,0,0);}
	| expr '|' expr{$$ = astGenerate(AST_OR,0,$1,$3,0,0);}
	| expr '&' expr {$$ = astGenerate(AST_AND,0,$1,$3,0,0);}
	| expr OPERATOR_LE expr  {$$ = astGenerate(AST_LE,0,$1,$3,0,0);}
	| expr OPERATOR_GE expr   {$$ = astGenerate(AST_GE,0,$1,$3,0,0);}
	| expr OPERATOR_EQ expr   {$$ = astGenerate(AST_EQ,0,$1,$3,0,0);}
	| expr OPERATOR_DIF expr  {$$ = astGenerate(AST_DIF,0,$1,$3,0,0);}
	;
func_arguments:
	func_arguments_list {$$ = $1;}
	| {$$ = 0;}
	;
func_arguments_list:
	expr ',' func_arguments_list {$$ = astGenerate(AST_FUNC_ARGUMENTS,0,$1,$3,0,0);}
	| expr {$$ = $1;}
	;

identifier: 
	TK_IDENTIFIER {$$ = astGenerate(AST_SYMBOL,$1,0,0,0,0);}//Identificador deve ser um nodo folha
	;

string:
	LIT_STRING{$$ = astGenerate(AST_SYMBOL,$1,0,0,0,0);} //String deve ser um nodo folha
	;
int:
	LIT_INTEGER{$$ = astGenerate(AST_SYMBOL,$1,0,0,0,0);} //Int deve ser um nodo folha
	;

varlit: 
	LIT_INTEGER {$$ = astGenerate(AST_SYMBOL,$1,0,0,0,0);} ////Deve ser um nodo folha
	| LIT_TRUE {$$ = astGenerate(AST_SYMBOL,$1,0,0,0,0); }//Deve ser um nodo folha
	| LIT_FALSE {$$ = astGenerate(AST_SYMBOL,$1,0,0,0,0);} //Deve ser um nodo folha
	| LIT_CHAR {$$ = astGenerate(AST_SYMBOL,$1,0,0,0,0); }//Deve ser um nodo folha
	;



%%

int yyerror(){
	
	printf("Erro de sintaxe na linha %d\n",getLineNumber());
	exit(3);
}

void loadOutFile(FILE *saida){
	outfile = saida;
}