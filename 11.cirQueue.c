#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXNUM 64
#define MAXLEN 1000
#define TRUE 1
#define FALSE 0

struct queue
{
	int num[MAXNUM];
	int *head;
	int *tail;
};

char *getterm(char *line, char *term);
int isEmpty(struct queue *q);
int isFull(struct queue *q);
void push(struct queue *q, int num);
void pop(struct queue *q);
void print(struct queue *q);

int main()
{
	int number;
	char line[MAXLEN];
	char term[MAXLEN];
	char *p;
	struct queue q;
	q.head = q.num;
	q.tail = q.num;

	while(fgets(line, MAXLEN, stdin))
	{
		number = 0;
		p = line;
		while(p = getterm(p, term))
		{
			if(!strcmp(term, "pop"))
			{
				while(*p && isspace(*p)) p++;
				if(*p != '\0') break;
				pop(&q);
			}
			if(!strcmp(term, "push"))
			{
				while(*p && !isdigit(*p)) p++;
				if(*p == '\0') break;
				p--;
				if(atoi(p) < -1000000 || atoi(p) > 1000000) break;
				push(&q, atoi(p));
			}
			if(!strcmp(term, "print")) 
			{
				while(*p && isspace(*p)) p++;
				if(*p != '\0') break;
				print(&q);
			}
		}
	}
	return 0;
}

char *getterm(char *line, char *term)
{
	char *ptr = line;
	char *qtr = term;
	while(isalpha(*ptr) && !isspace(*ptr))
	{
		*qtr++ = *ptr++;
	}
	*qtr = '\0';
	if(ptr - line == 0) return NULL;
	return ptr;
}

int isEmpty(struct queue *q)
{
	if(q->tail == q->head) return TRUE;
	return FALSE;
}

int isFull(struct queue *q)
{
	if(q->tail - q->head == (MAXNUM-1) || q->tail+1 == q->head) return TRUE;
	return FALSE;
}

void push(struct queue *q, int num)
{
	if(isFull(q)) printf("Is full!\n");
	else
	{
		if(q->tail - q->num == MAXNUM) q->tail = q->num;
		*q->tail = num;
		q->tail++;
	}
}

void pop(struct queue *q)
{
	int change = TRUE;
	if(isEmpty(q)) printf("Is empty!\n");
	else
	{
		if(q->head - q->num == MAXNUM) q->head = q->num;
		printf("Pop %d\n", *q->head);
		q->head++;
	}
}

void print(struct queue *q)
{
	int cnt=0;
	int change = TRUE;
	printf("Queue:");
	while(!isEmpty(q))
	{
		if(q->head - q->num == MAXNUM) q->head = q->num;
		cnt++;
		printf(" %d", *q->head);
		q->head++;
	}
	printf("\n");
	for(int i=0; i<cnt; i++)
	{
		if(q->head == q->num) q->head += MAXNUM;
		q->head--;
	}
}
