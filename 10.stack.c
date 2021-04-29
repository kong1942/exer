#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXNUM 64
#define MAXLEN 1024
#define TRUE 1
#define FALSE 0

struct stack
{
	int num[MAXNUM];
	int *top;
	int *bottom;
};


char *getterm(char *line, char *term);
int isEmpty(struct stack *s);
int isFull(struct stack *s);
void push(struct stack *s, int num);
void pop(struct stack *s);
void print(struct stack *s);

int main()
{
	char line[MAXLEN];
	char term[MAXLEN];
	char *p;
	struct stack s;
	s.top = s.num;
	s.bottom = s.num;

	while(fgets(line, MAXLEN, stdin))
	{
		p = line;
		while(p = getterm(p, term))
		{
			if(!strcmp(term, "pop")) pop(&s);
			if(!strcmp(term, "push")) push(&s, atoi(p));
			if(!strcmp(term, "print")) print(&s);
		}
	}
	return 0;
}

char *getterm(char *line, char *term)
{
	char *ptr = line;
	char *qtr = term;
	while(*ptr && isalpha(*ptr))
	{
		*qtr++ = *ptr++;
	}
	*qtr = '\0';
	if(ptr - line == 0) return NULL;
	return ptr;
}

int isEmpty(struct stack *s)
{
	if(s->top == s->bottom) return TRUE;
	return FALSE;
}

int isFull(struct stack *s)
{
	if(s->top - s->bottom == MAXNUM) return TRUE;
	return FALSE;
}

void push(struct stack *s, int num)
{
	if(isFull(s)) printf("Is full!\n");
	else
	{
		*s->top = num;
		s->top++;
	}
}

void pop(struct stack *s)
{
	if(isEmpty(s)) printf("Is empty!\n");
	else
	{
		s->top--;
		printf("Pop %d\n", *s->top);
	}
}

void print(struct stack *s)
{
	printf("Stack:");
	while(!isEmpty(s))
	{
		printf(" %d", *s->bottom);
		s->bottom++;
	}
	s->bottom = s->num;
	printf("\n");
}
