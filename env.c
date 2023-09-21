#include "shell.h"

/**
 * envn - to print the environment path
 * @env: to show path
 *
 *  number of args
 *  the NULL args
 * Return: Always 0 if success
 */

int envn(char **env)
{
	unsigned int a;

	a = 0;

	while (env[a] != NULL)
	{
		printf("%s\n", env[a]);
		a++;
	}
	return (0);
}
