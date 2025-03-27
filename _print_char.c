#include "main.h"

/**
 * _print_char - A helper function for _printf, printing a character.
 *
 * Description: When a conversion specifier "%c" is passed to _ptrinf, this
 *              function convert the argument into a character and print it.
 *
 * @arguments: The arguments list passed to _printf.
 *
 * Return: The number of printed character (1).
 */
int _print_char(va_list arguments)
{
unsigned char character = va_arg(arguments, int);

_putchar(character);
return (1);
}
