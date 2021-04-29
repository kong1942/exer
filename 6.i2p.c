#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 3072
#define MAXNUM 3072
#define TRUE 1
#define FALSE 0
 
char *check(char *line, char *term);
char *getwd(char *line);
char *priority(char *line);
char *priority2(char *line);

int main()
{
	char buf[MAXLEN];
	char term[MAXNUM];
	char operator[5] = "+-*/";
	char *p;
	char *q;
	int len;
	int isexp = FALSE;
	int cnt=0;
	
	while(fgets(buf, MAXLEN, stdin))
	{
		isexp = FALSE;
		len = strlen(buf);
		if(buf[len-1] == '\n') buf[len-1] = '\0';
		p = buf;
		
		if(*p == '(') p = check(p, term);
		q = p;
		while(*q)
		{
			if(*q && strchr(operator, *q)) isexp = TRUE;
			q++;
		}
		if(!isexp)
		{
			printf("%s\n", p);
			continue;
		}

		if(*p != '(') p = getwd(p);
		else p = priority(p);
		while(p) {p = priority2(p); if(p) printf(" ");}

		printf("\n");
	}
	return 0;
}

char *check(char *line, char *term)
{
	int cnt=0;
	char *p = line;
	char *q = term;
	if(*p != '(') return p;
	cnt++;
	p++;
	while(cnt)
	{
		if(*p == '(') cnt++;
		if(*p == ')') cnt--;
		if(cnt) *q++ = *p++;
	}
	*q = '\0';
	p++;
	if(*p) return line;
	
	char subterm[MAXNUM];
	return p = check(term, subterm);
}

char *getwd(char *line)
{
	char *p = line;
	char operator[5] = "+-*/";
 
	while(*p && !strchr(operator, *p))
	{
		printf("%c", *p++);
	}
	printf(" ");
	if(*p) return p; //next operator
	return NULL;
}

char *priority(char *line)
{
	int cnt = 0;
	int isexp = FALSE;
	char *p = line;
	char operator[5] = "+-*/";
	char term[MAXNUM];
	char *q = term;
	char opatr;

	cnt++;
	p++;
	while(cnt)
	{
		if(strchr(operator, *p)) isexp = TRUE;
		if(*p == '(') cnt++;
		if(*p == ')') cnt--;
		if(cnt) *q++ = *p++;
	}
	*q = '\0';
	q = term;
	if(*q == '(') q = priority(q);
	else q = getwd(q);
	while(q) {q = priority2(q); if(q) printf(" ");}

	p++;
	if(isexp) printf(" ");
	if(*p) return p; //next operator
	return NULL;
}
 
char *priority2(char *line)
{
	char *p = line;
	char operator[5] = "+-*/";
	char opatr;

	while(p && strchr(operator, *p))
	{
		opatr = *p;
		p++;
		if(opatr == '+' || opatr == '-')
		{
			if(*p != '(') p = getwd(p);
			else p = priority(p);
			if(p && (*p == '*' || *p == '/'))
			{
				p = priority2(p);
				printf(" ");
			}
			printf("%c", opatr);
			if(p) printf(" ");
		}
		if(opatr == '*' || opatr == '/')
		{
			if(*p != '(') p = getwd(p);
			else p = priority(p);
			printf("%c", opatr);
			if(p && (*p == '*' || *p == '/'))
			{
				printf(" ");
				p = priority2(p);
			}
			return p;
		}
	}
	return NULL;
}
