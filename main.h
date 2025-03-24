#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct conv_spe - A structure containing conversion specifier for _printf.
 *
 * Description: This structure contains :
 *                  - Every conversion specifier handeled by _printf function.
 *                  - For each specifier, a function pointer pointing to the
 *                    function called by the specifier.
 *
 * @specifier: The conversion specifier.
 * @func: The function associated, taking for input :
 *            - The format string passed to _printf.
 *            - The arguments list passed to _printf.
 */

typedef struct conv_spe
{
	char *specifier;
	int (*func)(va_list);
} conversion_specifier;

int _printf(const char *format, ...);
int _print_string(va_list);
int _print_char(va_list);
int _putchar(char c);

#endif
