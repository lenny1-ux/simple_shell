#include "shell.h"

/**
 * exist - does the file exist
 * @pathname: file path
 *
 * Return: if file is found 0, or else -1
 */

int exist(char *pathname)
{
	int exist_stat;

	exist_stat = (open(pathname, O_RDONLY));
	if (exist_stat != -1)
	{
		close(exist_stat);
		return (0);
	}
	else
		return (-1);
}
