#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 1024
#define MAXNAME 512
#define MAXHW 5
#define TRUE 1
#define FALSE 0

struct Lnode
{
	char name[MAXNAME];
	int hw[MAXHW];
	int sum;
	struct Lnode *next;
};

int checkline(char *line);
struct Lnode *insertNode(struct Lnode *nextnode, char *line);
struct Lnode *insertionSort(struct Lnode list);
void pntlist(struct Lnode *list);


int main()
{
	struct Lnode *list;
	struct Lnode *head;
	struct Lnode *ptr;
	char line[MAXLEN];
	list = NULL;
	head = NULL;

	while(fgets(line, MAXLEN, stdin))
	{
		if(checkline(line)) continue;
		
		list = insertNode(head, line);
		ptr = insertionSort(*list);
		if(ptr != NULL)
		{
			head = list->next;
			list->next = ptr->next;
			ptr->next = list;
		}
		else head = list;
	}
	list = head;
	pntlist(head);
	head = list;
	while(head)
	{
		head = list->next;
		free(list);
		list = head;
	}
	return 0;
}

int checkline(char *line)
{
	int cnt = 0;
	int flag = FALSE;
	char *p = line;

	while(*p)
	{
		if(!isalnum(*p) && !isspace(*p)) return TRUE;
		while(isdigit(*p)) {p++; flag = TRUE;}
		if(flag) {cnt++; flag = FALSE;}
		p++;
	}
	if(cnt != MAXHW) return TRUE; 
	return FALSE;
}

struct Lnode *insertNode(struct Lnode *nextnode, char *line)
{
	struct Lnode *student;
	student = (struct Lnode *)malloc(sizeof(struct Lnode));
	student->next = nextnode;
	student->sum = 0;
	char *p = line;
	char *name = student->name;

	while(isalpha(*p))
	{
		*name++ = *p++;
	}
	*name = '\0';
	for(int i=0; i<MAXHW; i++)
	{
		while(!isdigit(*p)) p++;
		student->hw[i] = atoi(p);
		while(isdigit(*p)) p++;
		student->sum += student->hw[i];
	}

	return student;
}

struct Lnode *insertionSort(struct Lnode list)
{
	int exchange = FALSE;
	struct Lnode *ptr;
	int listsum = list.sum;
	ptr = &list;

	while(ptr->next && ((ptr->next)->sum > listsum))
	{
		exchange = TRUE;
		ptr = ptr->next;
	}
	if(exchange) return ptr;
	else return NULL;
}

void pntlist(struct Lnode *list)
{
	struct Lnode *p = list;
	while(p)
	{
		printf("%s\t", p->name);
		for(int i=0; i<MAXHW; i++) 
		{
			printf("%d", p->hw[i]);
			if(i<MAXHW-1) printf("\t");
			else printf("\n");
		}
		p = p->next;
	}
}
