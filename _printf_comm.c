#include "main.h"

int _printf(const char *format, ...)
{
	/* VARIABLE DECLARATION, HANDLING VARIABLE ARGUMENTS */
	va_list arguments; /* Variable argument list */
	int index, bytes_count = 0; /* Index to traverse the format string */
	/* Counter for printed characters */

	va_start(arguments, format); /* INITIALIZE VARIABLE ARGUMENT LIST */
	if (format == NULL) /* Handle NULL format case (error) */
		return (-1);
	for (index = 0; format[index] != '\0'; index++)
	{ /* LOOP THROUGH EACH CHARACTER IN THE FORMAT STRING */
		if (format[index] != '%') /* Case1 Regular character (no specifier) */
		{
			_putchar(format[index]); /* Direct output */
			bytes_count++; /* Increment counter */
			continue; /* Skip to next iteration */
		} /* Case2 Format specifier start (%) */
		index++; /* Move to next character */
		if (format[index] == '\0') /* Handle premature end after % */
		{
			va_end(arguments); /* Clean up arguments */
			return (-1); /* Error: incomplete specifier */
		} /* PROCESS DIFFERENT FORMAT SPECIFIERS */
		else if (format[index] == 'c')
			bytes_count += _print_char(arguments); /* Character */

		else if (format[index] == 's')
			bytes_count += _print_string(arguments); /* String */

		else if (format[index] == '%')
			bytes_count += _print_percent(); /* Literal percent */

		else if (format[index] == 'd' || format[index] == 'i')
			bytes_count += _print_digit(arguments); /* Signed integer */

		else
			bytes_count += _print_other(format[index]); /* Unknown specifier */
	}
	va_end(arguments); /* Clean up variable arguments */
	return (bytes_count); /* Return total number of characters processed */
}
