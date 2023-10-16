#include "main.h"

/**
 * _printf - produces an output in stdout stream
 * @format: format string
 * Return: number of characters printed
 */

int _printf(const char *format, ...) {
    va_list args;
    int char_count = 0;

    va_start(args, format);

    while (format && *format) {
        if (*format != '%') {
            _putchar(*format);
            char_count++;
        } else {
            format++;
            if (*format == '\0')
                break;
            int printed = 0;

            if (*format == '%') {
                printed += print_percent();
            } else {
                int i;
                identifierStruct identifierArr[] = {
                    {"c", print_char},
                    {"s", print_str},
                    {"i", print_int},
                    {"d", print_int},
                    {"u", print_unsigned},
                    {"b", print_unsignedToBinary},
                    {"o", print_oct},
                    {"x", print_hex},
                    {"X", print_HEX},
                    {"S", print_STR},
                    {NULL, NULL}
                };

                for (i = 0; identifierArr[i].indentifier; i++) {
                    if (*format == identifierArr[i].indentifier[0]) {
                        printed += identifierArr[i].printer(args);
                        break;
                    }
                }

                if (identifierArr[i].indentifier == NULL)
                {
                    _putchar('%');
                    _putchar(*format);
                    printed = 2;
                }
            }

            char_count += printed;
        }

        format++;
    }

    va_end(args);
    return char_count;
}

