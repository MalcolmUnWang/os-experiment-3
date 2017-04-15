#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char * argv[])
{
	struct shmid_ds buffer;
	int shmid;
	int pid;
	char * shmaddr;
	shmid = shmget(IPC_PRIVATE,100,IPC_CREAT|IPC_EXCL|S_IRUSR|S_IWUSR);
	if ( argc != 2){
		printf("Input ONE and ONLY ONE string.\n");
		exit (-1);
	}
	pid = fork();  // fork a child process
	if (shmid <0){
		printf("Cannot creat a shared memory!\n");
		exit(1);
	}
	shmaddr = (char*)shmat(shmid,NULL,0);
	if(pid>0){
		strcpy( shmaddr, argv[1]);  // Write the message in father process.
		sleep(1);
		exit(0);
	}
	else if(pid  == 0){
		sleep(1);
		printf("Message %s has been transferred!\n",shmaddr);  // Read the message in the child process.
		exit(0);
	}
	return 0;
}
