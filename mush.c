//Caleb Knight
//CS344
//Write a shell in C

#include <stdio.h> //printf, fgets, perror
#include <stdlib.h> //exit
#include <string.h> //strtok, strcmp
#include <unistd.h> //fork, execvp
#include <sys/wait.h> //wait

int run_shell()
{
	char input[2048];
	char *new_argv[128];

	while(1)
	{
		int i = 0;
		char *token;

		printf("-ksh$ ");
		fflush(stdout); //Assure prompt display
		fgets(input, sizeof input, stdin); //Read line from stdin
		printf("%s\n", input);

		if ((token = strtok(input, " \t\n\r")) != NULL) {
			do {
				new_argv[i++] = token;
				printf("\"%s\"\n", token);
			} while ((token = strtok(NULL, " \t\n\r")) != NULL);
		}
		new_argv[i] = NULL;

		pid_t pid = fork();

		if(pid == 0) {
			execvp(new_argv[0], new_argv);
			perror("exec");
			exit(1);

		}

		return 1;
	}
}

int command_handler() 
{
 return 0;
}

int main(int argc, char *argv[])
{
	run_shell();
}