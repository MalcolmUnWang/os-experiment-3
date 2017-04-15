#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>


int main(int argc, int *argv[])
{
	const  char *fifo = "/tmp/my_fifo";
	char buffer[50];
	if ( access( fifo, F_OK)==-1){
		if(mkfifo(fifo, 0777) != 0){
			printf("Could not create fifo\n");
		}
	}
	while(1){                // The server will keep receiving message from clients.
		FILE *FIFO = fopen (fifo, "r");
		fscanf(FIFO,"%s",buffer);
		printf("Message %s has been transferred to the Server! \n",buffer);
		fclose(FIFO);	
		sleep(1);
	}
	return 0;
}
