#include "main.h"
#include <unistd.h>
#include <stdio.h>

/**
 * print_char - writes c to stdout
 * @arg: argument
 * @character: stores the argument retrieved using va_arg
 * Return: 1 for success,-1 for error
 */

int print_char(va_list arg)
{
	character = va_arg(arg, int);
	return (_putchar(character));
}

/**
 * print_int - prints an integer
 * @arg: argument
 * Return: 0
 */

int print_int(va_list arg)
{

	int divisor = 1, i, resp, charPrinted = 0;
	int n = va_arg(arg, int);

	if (n < 0)
	{
		_putchar('-');
		charPrinted++;
		n = -n;
	}
	if (n == 0)
	{
		_putchar('0');
		charPrinted++;
	}
	else
	{
		charPrinted += print_positive_int(n);
	}
	return (charPrinted);
}

int print_positive_int(unsigned int n)
{
	int charPrinted = 0;
	if (n / 10)
	{
		charPrinted = print_positive_int(n / 10);
	}
	_putchar('0' + n % 10);
	return (charPrinted + 1);
}

/**
 * print_STR - prints a string with an uppercase S specificer
 * @arg: argument
 * Return: number of printed characters
 */

int print_STR(va_list arg)
{
	int i;
	char *str = va_arg(arg, char*);

	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i]; i++)
	{
		if ((str[i] < 32 && str[i] > 0) || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			if (i < 16)
			{
				_putchar('0');
			}
			print_unsignedIntToHex(str[i], 'A');
		}
		else
		{
			_putchar(str[i]);
		}
	}
	return (i);
}

/**
 * print_str - prints a string with a lowercase s specifier
 * @arg: argument
 * Return: number of printed characters
 */

int print_str(va_list arg)
{
	int i;
	char *str = va_arg(arg, char*);

	if (str == NULL)
	{
		str = "(null)";
	}
	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
	return (i);
}

/**
 * print_unsigned - prints an unsigned int
 * @arg: argument
 * Return: 0
 */

int print_unsigned(va_list arg)
{
int charPrinted = 0;
unsigned int n = va_arg(arg, unsigned int);

	if (n == 0)
	{
		_putchar('0');
		charPrinted++;
	}
	else
	{
		charPrinted += print_unsigned_positive(n);
	}
	return (charPrinted);
}

int print_unsigned_positive(unsigned int n)
{
	int charPrinted = 0;

	if (n / 10)
	{
		charPrinted += print_unsigned_positive(n / 10);
	}
	_putchar('0' + n % 10);
	return (charPrinted + 1);
}
