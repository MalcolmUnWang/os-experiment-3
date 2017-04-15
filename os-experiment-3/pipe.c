//This program implement IPC by a pipe.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


int main (int argc, char *argv[])
{
	if (argc != 2){
		printf("Input one string after pipe command. \n");
		exit (1);
	}
	int fds[2];
	pid_t pid;
	char buffer[50];
	pipe(fds);
	pid = fork(); 	//Fork a child process
	if (pid == (pid_t) -1){
		printf("Child process cannot be forked! \n");
	}
	else if (pid == (pid_t) 0){
		close(fds[1]);
		read( fds[0], buffer , sizeof (buffer));  // Read pipe in the child process
		printf("Massage %s has been trandferred! \n", buffer);
		close(fds[0]);	
	}
	else{
		close(fds[0]);
		write(fds[1], argv[1], strlen(argv[1])+1);  // Write pipe in tge father process
		close(fds[1]);
	}
	return 0;
}
