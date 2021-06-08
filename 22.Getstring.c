#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 2048

int main()
{
	char line[MAXLEN];
	char line2[MAXLEN];
	line2[0] = '\0';
	char key = '\"';
	char *ptr, *qtr = NULL;

	while(fgets(line, MAXLEN, stdin))
	{
		ptr = line;
		while(ptr)
		{
			if(ptr = strchr(ptr, key))
			{
				ptr++;
				qtr = strchr(ptr, key);
				strcpy(line2, ptr);
				line2[qtr-ptr] = '\0';
				printf("%s\n", line2);
				ptr = qtr+1;
			}
		}
        }

	return 0;
}
