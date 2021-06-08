#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 66

struct BSnode 
{
	char *key;
	struct BSnode *L;
	struct BSnode *R;
};

struct BSnode *insert(struct BSnode *root, char *key)
{
	struct BSnode *p;
	if(root == NULL)
	{
		p = (struct BSnode *)malloc(sizeof(struct BSnode));
		p->key = strdup(key);
		p->L = NULL;
		p->R = NULL;
		return p;
	}
	char RL = '\0';
	struct BSnode *q = root;
	while(q)
	{
		p = q;
		if(strcmp(key, q->key) > 0)
		{
			RL = 'R';
			q = q->R;
		}
		else if(strcmp(key, q->key) < 0)
		{
			RL = 'L';
			q = q->L;
		}
		else return root;
	}
	if(RL == 'R') p->R = insert(p->R, key);
	else p->L = insert(p->L, key);
	return root;
}

void traversal(struct BSnode *root, char mode)
{
	if(root == NULL) return;
	if(mode == 'p')
	{
		printf("%s\n", root->key);
		traversal(root->L, mode);
		traversal(root->R, mode);
	}
	if(mode == 'P')
	{
		traversal(root->L, mode);
		traversal(root->R, mode);
		printf("%s\n", root->key);
	}
	if(mode == 'i')
	{
		traversal(root->L, mode);
		printf("%s\n", root->key);
		traversal(root->R, mode);
	}
}

int main(int argc, char **argv)
{
	if(argc != 2) exit(0);
	int len;
	char line[MAXLEN];
	struct BSnode *root = NULL;

	while(fgets(line, MAXLEN, stdin))
	{
		len = strlen(line);
		if(line[len-1] == '\n') line[len-1] = '\0';
		root = insert(root, line);
	}
	if(!strcmp(argv[1], "-p"))
	{
		traversal(root, 'p');
	}
	else if(!strcmp(argv[1], "-P"))
	{
		traversal(root, 'P');
	}
	else if(!strcmp(argv[1], "-i"))
	{
		traversal(root, 'i');
	}
	return 0;
}
