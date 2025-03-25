#include "main.h"

/**
 * _print_other - A helper function for _printf, printing an unhandeled
 *                conversion specifier.
 *
 * Description: When a conversion specifier is passed to _ptrinf and if this
 *              conversion specifier is not handeled by _printf, this function
 *              print it the conversion specifier directly.
 *
 * @c: The character of the conversion specifier.
 *
 * Return: The number of printed character (2).
 */
int _print_other(char c)
{
	_putchar('%');
	_putchar(c);
	return (2);
}
