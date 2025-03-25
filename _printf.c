#include "main.h"

/**
 * _printf - A function that produce output according to a format.
 *
 * Description: A variadic function, producing ouput refering to a format
 *              string. This format string specifies how are converted
 *              the different arguments for output.
 *              This function handeling ordinary characters, which are copied
 *              unchanged. If a conversion specifier is found, then the
 *              function do as follow:
 *                  "%c"    Convert the int argument to an unsigned char and
 *                          write it.
 *                  "%s"    Characters from the string argument, until
 *                          terminating null byte '\0', are written.
 *                  "%%"    Write a "%" character.
 *                 "d" "i"  Convert the int argument to signed decimal
 *                          notation and write it.
 *              This function do not handle the flag characters, field width,
 *              precision, or the length modifiers, and don't reproduce the
 *              buffer handling.
 *
 * @format: A string composed of zero or more directives.
 *
 * Return: If success, this function returns the number of characters printed
 *         (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	va_list arguments; /* Macro initializing argument list */
	int index, bytes_count = 0;

	va_start(arguments, format); /* Macro initializing argument list iteration */
	if (format == NULL)
		return (-1);
	for (index = 0; format[index] != '\0'; index++)
	{								/* Going through format string */
		if (format[index] != '%')
		{
			_putchar(format[index]); /* Write regular character */
			bytes_count++;
			continue; /* Go back to the loop to check the next character */
		}
		index++; /* Checking the next character after "%" */
		if (format[index] == '\0')
		{
			va_end(arguments);
			return (bytes_count);
		}
		else if (format[index] == 'c')
			bytes_count += _print_char(arguments);

		else if (format[index] == 's')
			bytes_count += _print_string(arguments);

		else if (format[index] == '%')
			bytes_count += _print_percent();

		else if (format[index] == 'd' || format[index] == 'i')
			bytes_count += _print_digit(arguments);

		else /* Handeling other conversion specifier */
			bytes_count += _print_other(format[index]);

	}
	va_end(arguments); /* Macro ending argument list iteration */
	return (bytes_count);
}
