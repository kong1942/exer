#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLEN 4096
#define MAXTERM 1024
#define MAXNUM 1500

struct stack
{
	double num[MAXNUM];
	double *top;
	double *bottom;
};

char *getterm(char *line, char *term, struct stack *s);
double pop(struct stack *s);
void push(struct stack *s, double num);

int main()
{
	char line[MAXLEN];
	char term[MAXTERM];
	char *p;
	struct stack *s;
	s = (struct stack *)malloc(sizeof(struct stack));
	s->top = s->num;
	s->bottom = s->num;

	while(fgets(line, MAXLEN, stdin))
	{
		p = line;
		while(p = getterm(p, term, s))
		{
		}
		printf("%.2f\n", pop(s));
	}

	free(s);

	return 0;
}

char *getterm(char *line, char *term, struct stack *s)
{
	char *ptr = line;
	char *qtr = term;
	double num1;
	double num2;
	double sum;

	
	while(*ptr && isspace(*ptr)) ptr++;
	while(*ptr && !isspace(*ptr)) 
	{
		*qtr++ = *ptr++;
	}
	*qtr = '\0';
	if(term[0] == '\0') return NULL;
	
	if(!strcmp(term, "+"))
	{
		num2 = pop(s);
		num1 = pop(s);
		sum = num1 + num2;
		push(s, sum);
	}
	else if(!strcmp(term, "-"))
	{
		num2 = pop(s);
		num1 = pop(s);
		sum = num1 - num2;
		push(s, sum);
	}
	else if(!strcmp(term, "*"))
	{
		num2 = pop(s);
		num1 = pop(s);
		sum = num1 * num2;
		push(s, sum);
	}
	else if(!strcmp(term, "/"))
	{
		num2 = pop(s);
		num1 = pop(s);
		sum = num1 / num2;
		push(s, sum);
	}
	else
	{
		push(s, atof(term));
	}
	return ptr;

}

double pop(struct stack *s)
{
	s->top--;
	return *s->top;
}

void push(struct stack *s, double num)
{
	*s->top = num;
	s->top++;
}
