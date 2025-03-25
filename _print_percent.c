#include "main.h"

/**
 * _print_percent - A helper function for _printf, printing a percent sign.
 *
 * Description: When a conversion specifier "%%" is passed to _ptrinf, this
 *              function convert the argument into a "%" and print it.
 *
 * Return: The number of printed character (1).
 */
int _print_percent(void)
{
	_putchar('%');
	return (1);
}
