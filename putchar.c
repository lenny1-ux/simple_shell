#include "shell.h"

/**
 * _putchar - prints character c to stdout
 * @c: character to print
 *
 * Return: 1 if success
 * Otherwise, if error -1, 
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
