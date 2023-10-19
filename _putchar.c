#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
* _putchar - writes the character c to stdout
* @c: The character to print
* Return: 1 for success and -1 for errors
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}
