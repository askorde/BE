%{

enum{
	LOOKUP = 0,
	VERB,
	ID,
	KEY,
	OP,
	PARA,
	LIT
};
int state;

void add_w(char *w,char *type);
int lookup(char *w);
%}

%%
\n	{state = LOOKUP;}

if	|
else	|
main	|
int	|
return	{//printf("Keyword:%s\n",yytext);//add_w(yytext,"KEY");
	}

[a-zA-Z][0-9a-zA-Z_]*	{//state = ID;printf("id:%s\n",yytext);	
	add_w(yytext,"ID");
	}
[+|\-|*|/]	{//state = OP;printf("op:%s\n",yytext);	//add_w(yytext,"OP");
	}

"("	|
")"	|
"{"	|
"}"	{//printf("para:%s\n",yytext);	add_w(yytext,"PARA");
	}

.	{}			
%%



typedef struct word{
	char *word_name;
	char *word_type;
	struct word *next;
}word;

word *word_list;

extern void *malloc();

int lookup(char *w)
{
	word *wp = word_list;
	for(;wp;wp=wp->next){
		if(strcmp(wp->word_name,w)==0)
			return 1;
	}
	return 0;
}
void add_w(char *w, char *type)
{
	if(!lookup(w))
	{
		word *wp;
		wp = (word*)malloc(sizeof(wp));
		wp->next = word_list;
		wp->word_name = (char*) malloc(strlen(w)+1);
		strcpy(wp->word_name, w);
		wp->word_type=type;
		word_list=wp;
	}
}

int main()
{
	FILE *f = fopen("text","r+");
	yyin = f;
	
	yylex();
	printf("SYMBOL TABLE:\n");
	word *wp = word_list;
	
	for(;wp;wp=wp->next){
		printf("%s",wp->word_name);
		
		printf("\n");
	}
	return 0;
}
int yywrap()
{
	return 1;
}
