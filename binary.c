#include "main.h"
#include <stdio.h>
#include <stddef.h>
/**
 * print_binary - prints a number in binary format
 * @n: number to be printed in binary format
 * @printed: the number of characters printed
 */

void print_binary(unsigned int n, unsigned int *printed)
{
	if  (n > 0)
	{
		*printed += 1;
		print_binary(n >> 1, printed);
	}
	_putchar((n & 1) + '0');
}
