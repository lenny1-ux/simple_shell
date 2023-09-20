#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_INPUT_SIZE / 2 + 1]; 
    char *token;
    int status;

    while (1) 
{
	printf("$ ");
	fflush(stdout);

	if (fgets(input, sizeof(input), stdin) == NULL)
	{
		if (feof(stdin))
		{
			printf("\n");
			break;
		} else
		{
			perror("Input error");
			exit(EXIT_FAILURE);
		}
	}

	input[strcspn(input, "\n")] = '\0';

	token = strtok(input, " ");
	int arg_count = 0;
	while (token != NULL)
	{
		args[arg_count] = token;
		token = strtok(NULL, " ");
		arg_count++;
	}
	args[arg_count] = NULL;

	if (arg_count == 0)
	{	
		continue;
        }
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	} else
	{
		wait(&status);

		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			printf("Exiting status: %d\n", exit_status);
		} else if (WIFSIGNALED(status))
		{
			int signal_number = WTERMSIG(status);
			printf("signaltermination: %d\n", signal_number);
		}
	}
	}
	return 0;
}

