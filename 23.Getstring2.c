#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 2048

int main()
{
	unsigned int bycnt=0, maxby=0;
	char line[MAXLEN];
	char line2[MAXLEN];
    line2[0] = '\0';
	char key1[] = "『", key2[] = "』", key3[] = "「", key4[] = "」";
	char *ptr, *qtr = NULL;

	while(fgets(line, MAXLEN, stdin))
	{
        if(ptr = strstr(line, key1))
        {
            ptr+=3;
            qtr = strstr(line, key2);
            bycnt = qtr-ptr;
            if(maxby < bycnt)
            {
                *qtr = '\0';
                maxby = bycnt;
                strcpy(line2, ptr);
            }
        }
        else if(ptr = strstr(line, key3))
        {
            ptr+=3;
            qtr = strstr(line, key4);
            bycnt = qtr-ptr;
            if(maxby < bycnt)
            {
                *qtr = '\0';
                maxby = bycnt;
                strcpy(line2, ptr);
            }
        }
	}
    printf("%s\n", line2);

	return 0;
}
