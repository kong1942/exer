#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 4096

int main()
{
	char line[MAXLEN];
	char str[MAXLEN];
	char *ptr = line;
	char *qtr = str;
	int hex1 = 0;
	int hex2 = 0;
	line[0] = '\0i';
	str[0] = '\0';
	
	while(fgets(line, MAXLEN, stdin))
	{
		ptr = line;
		qtr = str;
		if(line[strlen(line)-1] == '\n') line[strlen(line)-1] = '\0';
		while(*ptr)
		{
			if(!isalnum(*ptr) && *ptr != '.')
			{
				*qtr++ = '%';
				for(int i=0; i<4; i++)
				{
					hex1 += (*ptr & (1 << i+4));
				}
				hex1 = hex1 >> 4;
				for(int i=0; i<4; i++)
				{
					hex2 += (*ptr & (1 << i));
				}
				if(hex1 > 9) *qtr++ = hex1 - 10 + 'A';
				else *qtr++ = hex1 + '0';
				if(hex2 > 9) *qtr++ = hex2 - 10 + 'A';
				else *qtr++ = hex2 + '0';
				ptr++;
				hex1 = 0;
				hex2 = 0;
			}
			else 
			{
				*qtr++ = *ptr++;
			}
		}
		*qtr = '\0';
		printf("%s\n", str);
	}


	return 0;
}
