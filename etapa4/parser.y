%{
#include <stdio.h>
#include <stdlib.h>
#include "ast.h"
#include "hash.h"
#include "semantic.h"
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
%type<ast> literals
%type<ast> identifier

%type<ast> assign
%type <ast> command
%type <ast> block
%type <ast> print
%type <ast> type

%type <ast> programa
%type <ast> function
%type <ast> parameters
%type <ast> listparameters
%type <ast> decl
%type <ast> vector_value

%%

inicio: programa {check_and_set_declarations($1);check_undeclared();check_types($1);astMakeCode($1,outfile);/*astPrint($1,0);*/}
		;

programa: 
	decl ';' programa  {$$ = astGenerate(AST_LST_DECL,0,$1,$3,0,0);}
	| function ';' programa {$$ = astGenerate(AST_LST_FUNC,0,$1,$3,0,0);};
	| decl ';' {$$ = astGenerate(AST_LSTEND_DECL,0,$1,0,0,0);}
	| function ';' {$$ = astGenerate(AST_LSTEND_FUNC,0,$1,0,0,0);}
	;

decl: 
	type identifier ':' literals {$$ = astGenerate(AST_DECL_LIT,0,$1,$2,$4,0);}
	| type '[' int ']' identifier  ':' vector_value {$$ = astGenerate(AST_DECL_VEC,0,$1,$3,$5,$7);}
	| type '[' int']' identifier {$$ = astGenerate(AST_DECL_VEC_EMPTY,0,$1,$3,$5,0);}
	;

type: 
	KW_BOOL {$$ = astGenerate(AST_KW_BOOL,0,0,0,0,0);}
	|KW_CHAR {$$ = astGenerate(AST_KW_CHAR,0,0,0,0,0);}
	|KW_INT  {$$ = astGenerate(AST_KW_INT,0,0,0,0,0);}
	|KW_POINTER {$$ = astGenerate(AST_KW_POINTER,0,0,0,0,0);}
	;


vector_value: 
	literals vector_value {$$ = astGenerate(AST_LST_VEC1,0,$1,$2,0,0);}
	| literals {$$ = astGenerate(AST_LST_VEC2,0,$1,0,0,0);}
	;


function: 
	type identifier '(' parameters ')' command {$$ = astGenerate(AST_FUNCTION,0,$1,$2,$4,$6);}
	;


parameters: 
	listparameters {$$ = $1;}
	| {$$ = 0;}
	;

listparameters:
	type identifier ',' listparameters {$$ = astGenerate(AST_LST_PAR,0,$1,$2,$4,0);}
	| type identifier {$$ = astGenerate(AST_LST_PAREND,0,$1,$2,0,0);}

command:
	'{' block '}' { $$ = astGenerate(AST_BLOCK,0,$2,0,0,0);}
	| KW_READ identifier { $$ = astGenerate(AST_READ,0,$2,0,0,0);}
	| KW_RETURN expr { $$ = astGenerate(AST_RETURN,0,$2,0,0,0);}
	| assign {$$ = $1;}
	| KW_PRINT print { $$ = astGenerate(AST_PRINT,0,$2,0,0,0);}
	| KW_IF '(' expr ')' KW_THEN command { $$ = astGenerate(AST_IF,0,$3,$6,0,0);}
	| KW_IF '(' expr ')' KW_THEN command KW_ELSE command { $$ = astGenerate(AST_IFELSE,0,$3,$6,$8,0);}
	| KW_WHILE '(' expr ')' command  {$$ = astGenerate(AST_WHILE,0,$3,$5,0,0);}
	| {$$ = 0;}
	;

block:
	command ';' block { $$ = astGenerate(AST_BLOCKLST,0,$1,$3,0,0);}
	| {$$ = 0;}
	;

print: string { $$ = $1;}
	| expr { $$ = $1;}
	| string ',' print { $$ = astGenerate(AST_PRINTLST_STRING,0,$1,$3,0,0);}
	| expr ',' print { $$ = astGenerate(AST_PRINTLST_EXPR,0,$1,$3,0,0);}


assign:
	identifier LEFT_ASSIGN expr { $$ = astGenerate(AST_LEFT_ASSIGN,0,$1,$3,0,0);}
	| identifier '[' expr ']' LEFT_ASSIGN expr { $$ = astGenerate(AST_LEFT_ASSIGN_VEC,0,$1,$3,$6,0);}
	| expr RIGHT_ASSIGN identifier { $$ = astGenerate(AST_RIGHT_ASSIGN,0,$1,$3,0,0);}
	| expr RIGHT_ASSIGN identifier '[' expr ']' { $$ = astGenerate(AST_RIGHT_ASSIGN_VEC,0,$1,$3,$5,0);}
	;
expr:
	'(' expr ')' { $$ = astGenerate(AST_PARENTESIS,0,$2,0,0,0);}
	| identifier { $$ = $1;}
	| identifier '[' expr ']' { $$ = astGenerate(AST_VECTOR,0,$1,$3,0,0);}
	| literals {$$ = $1;}
	| identifier '(' func_arguments ')' { $$ = astGenerate(AST_EXPR_FUNCTION,0,$1,$3,0,0);}
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
	TK_IDENTIFIER {$$ = astGenerate(AST_SYMBOL_IDENTIFIER,$1,0,0,0,0);}//Identificador deve ser um nodo folha
	;

string:
	LIT_STRING{$$ = astGenerate(AST_SYMBOL_STRING,$1,0,0,0,0);} //String deve ser um nodo folha
	;
int:
	LIT_INTEGER{$$ = astGenerate(AST_SYMBOL_INT,$1,0,0,0,0);} //Int deve ser um nodo folha
	;

literals: 
	LIT_INTEGER {$$ = astGenerate(AST_SYMBOL_INT,$1,0,0,0,0);} ////Deve ser um nodo folha
	| LIT_TRUE {$$ = astGenerate(AST_SYMBOL_TRUE,$1,0,0,0,0); }//Deve ser um nodo folha
	| LIT_FALSE {$$ = astGenerate(AST_SYMBOL_FALSE,$1,0,0,0,0);} //Deve ser um nodo folha
	| LIT_CHAR {$$ = astGenerate(AST_SYMBOL_CHAR,$1,0,0,0,0); }//Deve ser um nodo folha
	;



%%

int yyerror(){
	
	printf("Erro de sintaxe na linha %d\n",getLineNumber());
	exit(3);
}

void loadOutFile(FILE *saida){
	outfile = saida;
}