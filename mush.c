//Caleb Knight
//CS344
//Write a shell in C

#include <stdio.h> //printf, fgets, perror
#include <stdlib.h> //exit
#include <string.h> //strtok, strcmp
#include <unistd.h> //fork, execvp
#include <sys/wait.h> //wait


int main(int argc, char *argv[])
{
	char input[2048];
	char *new_argv[128];

	while(1)
	{
		int i = 0;
		char *token;

		printf("Print a shell\n");
		fflush(stdout);
		fgets(input, sizeof input, stdin);

		if((token = strtok(input, " \t\n\r")) !=NULL)
		{
			do{
			new_argv[i++] = token;
		} while((token = strtok(input, " \t\n\r")) !=NULL);
		printf("%s\n", token);
	}

		new_argv[i] = NULL;

		

	}
}