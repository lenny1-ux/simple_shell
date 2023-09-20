#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

/**
 * main - Loop for the Simple Shell
 *
 * The program resembles a basic shell, it  uses commands,
 * It forks process and executes them, and displays the output
 * Return: 0 on success
 */
int main(void)
{
	char input[MAX_COMMAND_LENGTH];
	pid_t pid;

	while (1)
	{
		printf("$ ");

		if (fgets(input, sizeof(input), stdin) == NULL)
			{
				 printf("\n");
				break;
			}
			input[strlen(input) - 1] = '\0';
			pid = fork();

		if (pid == -1)
		{
			perror("fork");
		}

		else if (pid == 0)
		{
			if (execlp(input, input, NULL) == -1)
			{
				printf("Command error: %s\n", input);
				exit(EXIT_FAILURE);
			}
		} else
		{
			int status;

			if (waitpid(pid, &status, 0) == -1)
			{
				perror("pid err");
			}
		}
	}
	return (0);
}
