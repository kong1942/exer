#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void errmsg(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

int main(int argc, char **argv)
{
	if(argc != 2) errmsg("input error");
	FILE *fp;
	int c;
	if((fp = fopen(argv[1], "r+")) == NULL)
		errmsg("fopen error");

	while((c = fgetc(fp)) != EOF)
	{
		if(isupper(c))
		{
			if(fseek(fp, -1, SEEK_CUR) == -1)
				errmsg("fseek error");
			if(fputc(c-'A'+'a', fp) == EOF)
				errmsg("fpuc error");
		}
	}
	
	fclose(fp);
	
	return 0;
}
