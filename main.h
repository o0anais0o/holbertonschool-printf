#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _print_string(va_list arguments);
int _print_char(va_list arguments);
int _putchar(char c);
int egde_check(int digit);
char *rev_string(char *number_str, int length);
int _print_digit(va_list arguments);

#endif
