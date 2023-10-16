#include "main.h"

/**
 * printIdentifier - Function to print a single identifier based on format
 * @format: The format character
 * @arg: The va_list argument
 * Return: The number of characters printed
 */
int printIdentifier(char format, va_list arg) {
    switch (format) {
        case 'c':
            return print_char(arg);
        case 's':
            return print_str(arg);
        case 'd':
        case 'i':
            return print_int(arg);
        case 'u':
            return print_unsigned(arg);
        case 'b':
            return print_unsignedToBinary(arg);
        case 'o':
            return print_oct(arg);
        case 'x':
            return print_hex(arg);
        case 'X':
            return print_HEX(arg);
        case 'S':
            return print_STR(arg);
        default:
            return 0;
    }
}

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
 */
int _printf(const char *format, ...) {
    int charPrinted = 0;
    va_list arg;

    va_start(arg, format);

    if (format == NULL)
        return -1;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            if (format[i + 1] == '\0')
                return -1;

            int identifierPrinted = printIdentifier(format[i + 1], arg);

            if (identifierPrinted == -1 || identifierPrinted != 0) {
                i++;
            }

            charPrinted += identifierPrinted;

            if (identifierPrinted == 0) {
                _putchar('%');
                charPrinted++;
            }
        } else {
            _putchar(format[i]);
            charPrinted++;
        }
    }

    va_end(arg);
    return charPrinted;
}

