#include "shell.h"
#include <stdlib.h>
/**
 * main - to call external environment
 *
 *Return: 0 always
 */

int main(void)
{
	extern char** environ;
	char** env = environ;


	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}
