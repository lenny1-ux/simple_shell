#include "shell.h"

/**
 * env_path - to print path envirn
 *
 *Return: o success, or else -1 fail
 *
 */

void env_path(void)
{
	char *path = getenv("PATH");

	if (path != NULL)
	{
		char *token = strtok(path, ":");

		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, ":");
		}

	}
	else
	{
		printf("no Path");
	}



}
