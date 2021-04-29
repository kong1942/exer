#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 4096

void err()
{
	printf("error format\n");
}

void decode(char *buf)
{
	char *p = buf;
	char c1 = '\0';
	char c2 = '\0';
	char c;

	while(*p)
	{
		if(*p != '%')
		{
			printf("%c", *p);
		}
		else
		{
			p++;
			if(isdigit(*p))
			{
				c1 = (*p-'0') << 4;
				p++;
				if(isdigit(*p))
				{
					c2 = (*p-'0');
				}
				else
				{
					c2 = (*p-'A') + 10;
				}
				c = c1 | c2;
			}
			else
			{
				c1 = ((*p-'A') + 10) << 4;
				p++;
				if(isdigit(*p))
				{
					c2 = (*p-'0');
				}
				else
				{
					c2 = (*p-'A') + 10;
				}
				c = c1 | c2;
			}
			printf("%c", c);
		}
		p++;
	}
}

int checkbuf(char *buf)
{
	char *p = buf;
	while(*p)
	{
		
		if(*p == '%')
		{
			p++;
			if(((*p < 'A' || *p > 'F') && !isdigit(*p)) || (((*(p+1) < 'A' || *(p+1) > 'F')) && !isdigit(*(p+1))))
			{
				err();
				return 1;
			}
		}
		else p++;
	}
	return 0;
}

int main()
{
	char buf[MAXLEN];
	int check;

	while(fgets(buf, MAXLEN, stdin))
	{
		check = checkbuf(buf);
		if(check) continue;
		decode(buf);
	}
	return 0;
}
