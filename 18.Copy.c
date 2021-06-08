#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define MAXLEN 4096

void errmsg(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

int main(int argc, char **argv)
{
	if(argc != 3) errmsg("input error");
	int fd, fd2, len;
	char buf[MAXLEN];

	if((fd = open(argv[1], O_RDONLY)) == -1)
		errmsg("file1 open error");
	
	if((fd2 = open(argv[2], O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR | S_IRGRP | S_IROTH)) == -1)
		errmsg("file2 open error");
	
	while((len = read(fd, buf, MAXLEN)) > 0)
	{
		if(write(fd2, buf, len) == -1) errmsg("write error");
	}
	if(len == -1) errmsg("read error");
	
	buf[0] = '\0';

	close(fd2);
	close(fd);
	       
	return 0;
}
