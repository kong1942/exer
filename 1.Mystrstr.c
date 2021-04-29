#include <stdio.h>
#include <stdlib.h>
#define MAXLINELEN 3100
#define MAXSTRLEN 2048
#define MAXWDLEN 1024

int mystrstr(char *str, char *wd, int wLen)
{
	int i = 0;
	int start = 0;
	int stridx = -1;
	char *ptr = str;

	while(*ptr)
	{
		while(*ptr != wd[0] && *ptr) 
		{
			ptr++;
			start++;
		}	
		for(i=0; i<wLen; i++)
		{
			if(ptr[i] != wd[i]) break;
		}
		if(i != wLen && *ptr) 
		{
			start++;
			ptr++;
		}
		else if(*ptr)
		{
			stridx = start;
			start++;
			ptr++;
		}
	}
	return stridx;

}

int main()
{
	char *ptr, *qtr, *wtr;
	char line[MAXLINELEN];
	char str[MAXSTRLEN];
	char wd[MAXWDLEN];
	char delimiter[2] = ",";
	int start, end;
	int sLenCnt = 0;
	int wLenCnt = 0;
	line[0] = '\0';
	str[0] = '\0';
	wd[0] = '\0';
	
	while(fgets(line, MAXLINELEN, stdin))
	{
		ptr = line;
		qtr = str;
		wtr = wd;
		sLenCnt = 0;
		wLenCnt = 0;
		
		//divide string & word
		while(*ptr != ',' && *ptr)
		{
			*qtr++ = *ptr++;
			sLenCnt++;
		}
		*qtr = '\0';
		if(*ptr == ',') ptr++;
		while(*ptr)
		{
			*wtr++ = *ptr++;
			wLenCnt++;
		}
		*wtr = '\0';
		if(*(wtr-1) == '\n') *wtr = '\0';
		wLenCnt--;

		start = mystrstr(str, wd, wLenCnt);
		end = start + wLenCnt - 1;
		if(start == -1 || wd[0] == '\0' || str[0] == '\0') printf("-1\n");
		else printf("%d,%d\n", start, end);
	}

	return 0;
}
