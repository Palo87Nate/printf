#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
* _putchar - writes the character c to stdout
* @c: character to print
* Return: 1 for success or -1 for error, and errno is set appropriately.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
