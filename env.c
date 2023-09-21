#include "shell.h"

/**
 * main - to print the environment path
 *
 * @ac: number of args
 * @av: the NULL args
 * Return: Always 0 if success
 */

int envn( char **env)
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
