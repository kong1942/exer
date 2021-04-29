#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 1024
#define MAXNAME 1024

struct transcript
{
	char name[MAXNAME];
	int hw[5];
	int sum;
};

void getGrades(char *buf, struct transcript *s)
{
	int cnt=0;
	int i=0;
	char *p = buf;
	char *q = (*s).name;
	while(*p)
	{
		while(isalpha(*p))
		{	
			*q++ = *p++;
		}
		*q = '\0';
		if(isdigit(*p))
		{
			(*s).hw[i] = atoi(p);
			i++;
		}
		while(isdigit(*p)) p++;
		p++;
	}
	(*s).sum = 0;
	for(i=0; i<5; i++) (*s).sum += (*s).hw[i];
}

int main()
{
	char buf[MAXLEN];
	struct transcript student[100];
	int i=0, j=0, k=0;
	struct transcript tmp;
	
	while(fgets(buf, MAXLEN, stdin))
	{
		getGrades(buf, &student[i]);
		i++;
	}
	for(j=0; j<i-1; j++)
		for(k=0; k<i-j-1; k++)
		{
			if(student[k].sum < student[k+1].sum)
			{
				tmp = student[k];
				student[k] = student[k+1];
				student[k+1] = tmp;
			}
		}
	for(j=0; j<i; j++)
	{
		printf("%s\t", student[j].name);
		for(k=0; k<5; k++)
		{	
			printf("%d", student[j].hw[k]);
			if(k<4) printf("\t");
			else printf("\n");
		}
	}
	return 0;
}
