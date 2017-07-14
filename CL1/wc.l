%{
	#include<stdio.h>
	int alpha,lines,spaces,digits,tabs,words,chars,spl;
%}

%%
[0-9]	digits++;
[b+][a-z]* {for(int i=0;i<yyleng;i++){
				printf("%c",yytext[i]-32);
				}
			printf("\n");alpha+=yyleng;++words;
			}
[A-Za-z]+[a-z]*	{++words;alpha+=yyleng;}
\n	++lines;
\t ++tabs;
[ ]	++spaces;

.	++spl;
%%

int main()
{
	yyin = fopen("myfile.txt","r");
	yylex();
	printf("\n\nAlphabets=%d\n",alpha);
	printf("Digits=%d\n",digits);
	printf("Special Chars=%d\n",spl);
	printf("Total Character=%d\n\n",(alpha+digits+spl));
	
	printf("Words=%d\n",words);
	printf("Lines=%d\n",lines);
	printf("Spaces=%d\n",spaces);
	printf("Tabs=%d\n",tabs);
	return 0;
}
int yywrap()
{
	return 1;
}
