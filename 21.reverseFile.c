#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFSIZE 4096

void errmsg(char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(1);
}

int main(int argc, char **argv)
{
	if(argc != 2) errmsg("input error");
	struct stat stbuf;
	char *buf;
	int fd;
	unsigned int filesize;
	if((fd = open(argv[1], O_RDWR)) == -1)
		errmsg("open error");
	
	fstat(fd, &stbuf);
	filesize = stbuf.st_size;

	if((buf = (char *)malloc(sizeof(char)*(filesize+1))) == NULL)
		errmsg("malloc failed.");
	
	if(read(fd, buf, filesize) == -1)
		errmsg("read error");
	
	char *ptr = &buf[filesize-1];
	while(*ptr == '\n') {ptr--;}
	lseek(fd, 0, SEEK_SET);
	while(ptr != buf-1) {write(fd, ptr--, 1);}

	free(buf);
	close(fd);
	return 0;
}
