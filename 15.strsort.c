#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1024
#define MAXLINE 32

void merge(char **line, char **line2, int head, int tail)
{
	int i = head;
	int j = (tail+head)/2;
	int k = head;
	while(k < tail)
	{
		if(j == tail || i < (tail+head)/2 && strcmp(line[i], line[j]) <= 0)
		{
			line2[k] = strdup(line[i]);
			i++;
			k++;
		}
		else if(i == (tail+head)/2 || j<tail && strcmp(line[i], line[j]) > 0)
		{
			line2[k] = strdup(line[j]);
			j++;
			k++;
		}
	}
	for(int x=head; x<tail; x++)
		strcpy(line[x], line2[x]);
}

void mergesort(char **line, char **line2, int head, int tail)
{
	if(tail > head+1)
	{
		int pivot = (head + tail)/2;
		mergesort(line, line2, head, pivot);
		mergesort(line, line2, pivot, tail);
		merge(line, line2, head, tail);
	}
}

int main()
{
	int i, len;
	char **line = (char **)malloc(sizeof(char *)*MAXLINE);
	for(i=0; i<MAXLINE; i++)
		line[i] = (char *)malloc(sizeof(char)*MAXLEN);
	char **line2 = (char **)malloc(sizeof(char *)*MAXLINE);
	
	i=0;
	while(fgets(line[i], MAXLEN, stdin))
	{
		len = strlen(line[i]);
		if(line[i][len-1] == '\n') line[i][len-1] = '\0';
		i++;
	}
	mergesort(line, line2, 0, i);

	for(int x=0; x<i; x++)
		printf("%s\n", line[x]);

	for(i=0; i<MAXLINE; i++)
	{
		free(line[i]);
		free(line2[i]);
	}
	free(line);
	free(line2);
	return 0;
}
