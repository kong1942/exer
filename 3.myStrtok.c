#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXBUFLEN 2048
#define MAXLEN 1024

char *rm(char *str)
{
	char *ptr = str;
	char *qtr = str;
	while(*qtr)
	{
		if(*(qtr-1) == ',' && *qtr == ',') qtr++;
		else *ptr++ = *qtr++;
	}
	*ptr = '\0';
	return str;
}

int main()
{
	int check;
	int delimLen;
	char buf[MAXBUFLEN];
	char str[MAXLEN];
	char delim[MAXLEN];
	char str2[MAXLEN];
	char *ptr, *sptr, *s2ptr, *dptr;

	
	buf[0] = '\0';
	while(fgets(buf, MAXBUFLEN, stdin))
	{
		str[0] = '\0';
		str2[0] = '\0';
		delim[0] = '\0';

		if(buf[strlen(buf)-1] == '\n') buf[strlen(buf)-1] = '\0';
		ptr = buf;
		sptr = str;
		dptr = delim;
		
		//get string
		while(*ptr != ' ' && *ptr)
		{
			*sptr++ = *ptr++;
		}
		*sptr = '\0';
		sptr = str;
		if(*ptr == ' ') ptr++;
		
		//get delimiter
		while(*ptr)
		{
			*dptr++ = *ptr++;
		}
		*dptr = '\0';
		dptr = delim;

		ptr = buf;
		sptr = str;
		s2ptr = str2;
		dptr = delim;
		delimLen = strlen(dptr);
		while(*sptr)
		{
			if(*dptr == *sptr && *sptr)
			{
				check = strncmp(sptr, dptr, delimLen);
				if(!check)
				{
					sptr += delimLen;
					*s2ptr++ = ',';
				}
				else *s2ptr++ = *sptr++;
			}
			else *s2ptr++ = *sptr++;
		}
		*s2ptr = '\0';
		s2ptr = str2;

		s2ptr = str2;
		sptr = str2;
		while(*sptr == ',') sptr++;
		s2ptr = sptr;
		while(*sptr) sptr++;
		sptr--;
		while(*sptr == ',') sptr--;
		ptr = str2;
		check = 0;
		while(s2ptr <= sptr)
		{
			check = 1;
			*ptr++ = *s2ptr++;
		}
		*ptr = '\0';
		ptr = rm(str2);
		if(check) printf("%s\n", str2);
		else printf("empty string\n");
	}

	return 0;
}
