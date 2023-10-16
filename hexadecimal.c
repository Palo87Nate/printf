#include "main.h"
#include <unistd.h>
#include <math.h>

/**
 * print_hex_base - base for printing hexadecimal numbers
 * @arg: argument list containing hexadecimal
 * @_case: a for lowercase, A for uppercase
 * Return: number ofcharacters printed
 */

int print_hex_base(va_list arg, char _case)
{
	unsigned int num = va_arg(arg, unsigned int);
	int printed;

	if (num == 0)
	{
		return (_putchar('0'));
	}
	printed = print_unsignedIntToHex(num, _case);

	return (printed);
}
/**
 * print_hex - prints a hexadecimal in lower case
 * @arg: list that contains hexadecimal to print
 * Return: number of digits printed
 */

int print_hex(va_list arg)
{
	return (print_hex_base(arg, 'a'));
}

/**
 * print_HEX - prints a hexadecimal in upper case
 * @arg: list that contains hexadecimal to print
 * Return: number of digits printed
 */

int print_HEX(va_list arg)
{
	return (print_hex_base(arg, 'A'));
}
