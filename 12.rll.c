#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 65

struct Lnode
{
	char word[MAXLEN];
	struct Lnode *next;
	struct Lnode *last;
};

struct Lnode *insertAtFront(struct Lnode *nextnode, char *line)
{
	struct Lnode *list;
	list = (struct Lnode *)malloc(sizeof(struct Lnode));
	strcpy(list->word, line);
	list->next = nextnode;
	if(nextnode != NULL)
	{
		nextnode->last = list;
		list->last = NULL;
	}
	return list;
}

void pntlist(struct Lnode *head)
{
	struct Lnode *list = head;
	while(list->next)
	{
		if(list->word[0] != '\0') printf("%s\n", list->word);
		list = list->next;
	}
	if(list->word[0] != '\0') printf("%s\n", list->word);
	while(list->last)
	{
		if(list->word[0] != '\0') printf("%s\n", list->word);
		list = list->last;
	}
	if(list->word[0] != '\0')printf("%s\n", list->word);
}

int main()
{
	struct Lnode *head;
	struct Lnode *l;
	int len;
	char line[MAXLEN];
	head = NULL;
	
	while(fgets(line, MAXLEN, stdin))
	{
		len = strlen(line);
		while(line[len-1] == '\n') len--;
		line[len] = '\0';
		head = insertAtFront(head, line);
	}
	l = head;
	pntlist(head);
	head = l;
	while(head)
	{
		head = l->next;
		free(l);
		l = head;
	}
	return 0;
}
