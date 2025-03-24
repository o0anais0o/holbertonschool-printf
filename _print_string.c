#include "main.h"

/**
 * _print_string - A helper function for _printf, printing a string.
 *
 * Description: When a conversion specifier "%s" is passed to _ptrinf, this
 *              function prints the string from the arguments list.
 *
 * @arguments: The arguments list passed to _printf.
 *
 * Return: The count of printed characters.
 */

int _print_string(va_list arguments)
{
int count_byte = 0;
int index;
char *string = va_arg(arguments, char *);

if (string == NULL) /* Check if str is NULL */
	string = "(null)"; /* If NULL, fill str with "(null)" to print it */

for (index = 0; string[index] != '\0'; index++)
{
	_putchar(string[index]);
	count_byte++;
}
return (count_byte);
}
