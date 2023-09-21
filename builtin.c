#include "shell.h"

/**
 * execute_cd - to print commands
 *@args: to pass arguments
 *Return: current status
 */




void execute_cd(char *args[])
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: missing argument\n");
	} else
	{
		if (chdir(args[1]) != 0)
		{
			perror("cd");
		}
	}
}

/**
 * execute_exit - to escape shell
 *
 *Return: 0 passed
 *
 */

void execute_exit(void)
{

	char *args[1];

	if (strcmp(args[1], "exit") == 0)
	{
		exit(0);
	}
}

/**
 * execute_history - show previous history
 *
 * Return: 1 success
 */
void execute_history(void)
{
	printf("No command history in this simple shell\n");
}


/**
 * execute_ls -  list files command
 * show all files
 *
 */
void execute_ls(void)
{
	system("ls");
}

/**
 * execute - cmd execution
 * search all the PATH
 * @argv: arguments to be parsed
 *
 * @linkedlist_path: the form of path searched
 *
 * Return: 0 success, fail -1
 */

