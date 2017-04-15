#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<limits.h>

int main (int argc, char *argv[])
{
	if(argc!=2){
		printf("Input and only input one string! \n");
		exit(1);
	}
	const char *fifo = "/tmp/my_fifo";
	int  fd = open(fifo,O_WRONLY);
	if(fd != -1){
		write (fd, argv[1], strlen(argv[1]+1));
		close(fd);
	}
	else
		exit(-1);
	printf("Message %s has been sent from client!\n",argv[1]);
	exit(0);
}
