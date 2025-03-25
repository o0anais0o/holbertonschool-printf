# C - printf

## Description
This project simulates key functionalities of C's printf function.
We will create a printf function. Whith :
    write, malloc, free, va_start, va_end, va_copy, va_arg.

## Compilation Command
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c

## Requirements
- C

## Man page
The man page provides a detailed explanation of the function. To see the full documentation, run our man page like this:
./man_3_printf

## Exemples


## Test ✔️

• tests: Folder of test files. Provided by Holberton School.


## Header File 📁

• main.h: Header file containing definitions and prototypes for all types and functions written in the project.

| File                      | Prototype                                         |
| -----------               | -----------                                       |
| _printf.c                 | int _printf(const char *format, ...);             |
| _printf_string.c          | int _print_string(va_list arguments);             |
| _print_char               | int _print_char(va_list arguments);               |
| _putchar.c                | int _putchar(char c);                             |
| _print_digit.c            | int egde_check(int digit);                        |
| _print_digit.c            | char *rev_string(char *number_str, int length);   |
| _print_digit.c            | int _print_digit(va_list arguments);              |

## Flowchart
<img src="![alt text](image-1.png)" alt="flowchart">


## Authors
* Anaïs Choisy https://github.com/o0anais0o
* Valentin Dumont https://github.com/proser-v