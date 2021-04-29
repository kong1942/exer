#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 65
#define TRUE 1
#define FALSE 0

struct Lnode
{
	char term[MAXLEN];
	int cnt;
	struct Lnode *next;
};

struct Lnode *find(struct Lnode head, char *line);
struct Lnode *insert(char *line);

int main()
{
	int first = TRUE;
	int len;
	struct Lnode *head;
	struct Lnode *l;
	struct Lnode *f;
	char line[MAXLEN];
	char *p;
	l = NULL;

	while(fgets(line, MAXLEN, stdin))
	{
		len = strlen(line);
		if(line[len-1] == '\n') {line[len-1] = '\0'; len--;}

		p = line;
		if(*p)
		{
			if(first)
			{
				head = insert(p);
				l = head;
				first = FALSE;
			}
			else
			{
				if(!strcmp(head->term, p)) head->cnt++;
				else if(f = find(*head, p)) f->cnt++;
				else 
				{
					l->next = insert(p);
					l = l->next;
				}
			}
		}
	}

	l = head;
	while(head)
	{
		printf("%s %d\n", head->term, head->cnt);
		head = head->next;
	}
	head = l;
	while(head)
	{
		head = l->next;
		free(l);
		l = head;
	}

	return 0;
}

struct Lnode *find(struct Lnode head, char *line)
{
	struct Lnode *f;
	f = head.next;
	while(f && strcmp(f->term, line))
	{
		f = f->next;
	}
	return f;
}

struct Lnode *insert(char *line)
{
	struct Lnode *l;
	l = (struct Lnode *)malloc(sizeof(struct Lnode));
	char *p = line;
	char *q = l->term;
	while(*p)
	{
		*q++ = *p++;
	}
	l->cnt=1;
	l->next = NULL;
	return l;
}
