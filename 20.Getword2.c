// < 128 ASCII
// < 240 3 Bytes開頭
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 2048

int main()
{
	int i;
	char line[MAXLEN];
	char *ptr;
	char wd[4];

	while(fgets(line, MAXLEN, stdin))
	{
		ptr = line;
		while(*ptr)
		{
			if((unsigned char) *ptr < 128)
			{
				if(isalpha(*ptr))
				{
					while(isalpha(*ptr)) printf("%c", *ptr++);
					printf("\n");
				}
				else {ptr++;}
			}
			else if((unsigned char) *ptr < 240)
			{
				for(i=0; i<3; i++)
					wd[i] = *ptr++;
				wd[i] = '\0';
				printf("%s\n", wd);
			}
			else ptr++;
		}
	}
	return 0;
}
