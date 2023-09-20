#include "shell.h"

#define MAX_INPUT_SIZE 1024

/**
  * main - Looping the terminal
  *
  *Return: 0 Always
  *
  */

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *args[MAX_INPUT_SIZE / 2 + 1];
	char *token;
	pid_t pid;
	int arg_count;
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
		}
		{
			perror("Input error");
			exit(EXIT_FAILURE);
		}
	}

	input[strcspn(input, "\n")] = '\0';

	token = strtok(input, " ");
	arg_count = 0;

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

	pid = fork();
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
	return (0);
}

