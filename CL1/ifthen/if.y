%{
#include<stdio.h>
#include<stdlib.h>
%}
%token IF
%token ELSE
%token ID
%token FOR
%token NUM
%token WHILE
%%
stmt1:st
	|stmt1 st 
	;
st:';'
	|asgnst
	|ifstmt
	|forstmt
	|whilest
	;
stmts:st
	|stmts st
	;
incst:ID'='expr
	|ID'='NUM
	;
asgnst:incst';'
	;			
ifstmt:IF'('cond')'block	{printf("VALID IF STMT\n");}
	|ifstmt elsest
	;
block:'{'stmts'}'
	|'{''}'
	;
elsest:ELSE block
	|elsest ELSE block
	;
forstmt:FOR'('asgnst cond';'incst')'block	{printf("VALID FOR STMT\n");}
	;
whilest:WHILE'('cond')'block	{printf("VALID WHILE STMT\n");}
	;	
cond:ID'<'ID
	|ID'>'ID
	|ID'=''='ID
	;
expr:ID
	|NUM
	|expr'+'expr
	|expr'-'expr
	|expr'*'expr
	|expr'/'expr
	|cond	
%%

extern FILE *yyin;

int main()
{
	yyin = fopen("inp","r+");
	yyparse();
	return 0;
}		
void yyerror()
{
	printf("INVALID!");
}
