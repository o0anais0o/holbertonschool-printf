#include "main.h"

/**
 * egde_check - A helper function for _print_digit, checking for edge cases.
 *
 * Description: This function check if the integer passed to the function is
 *              0 or the minimal integer value "-2147483648" because
 *              _print_digit would produce an error making this value
 *              positive and bigger than the maximum value of an integer
 *              "2147483647".
 *
 * @digit: The integer passed as argument to _printf.
 *
 * Return: The number of printed character, 0 if nothing is printed.
 */

int egde_check(int digit)
{
	if (digit == 0) /* Case 1: Zero value */
	{
		write(1, "0", 1); /* Directly output character '0' */
		return (1); /* 1 character printed */
	}
	 /* Case 2: INT_MIN (avoids overflow in negation) */
	if (digit == -2147483648)
	{
		write(1, "-2147483648", 11); /* Hardcoded output */
		return (11); /* 11 chars printed */
	}
	/* Default: Not an edge case */
	return (0); /* Indicates normal processing required */
}

/**
 * rev_string - A helper function for _print_digit, that reverse a string.
 *
 * Description: This function reverse a string char by char.
 *
 * @number_str: The string to reverse.
 * @length: The length of the string to reverse.
 *
 * Return: The reversed string.
 */

char *rev_string(char *number_str, int length)
{
	int index, index2, reverse;
	/* Reversal loop: swaps opposite characters */
	for (index = 0, index2 = length - 1; index < index2; index++, index2--)
	{
		reverse = number_str[index]; /* Save left character */
		number_str[index] = number_str[index2]; /* Replace left with right */
		number_str[index2] = reverse; /* Replace right with saved left */
	}
	return (number_str); /* Returns the reversed string */
}

/**
 * _print_digit - A helper function for _printf, printing a signed integer.
 *
 * Description: When a conversion specifier "%d" or "%i" is passed to _ptrinf,
 *              this function prints the integer from the "format" arguments.
 *
 * @arguments: The arguments list passed to _printf.
 *
 * Return: The count of printed characters.
 */

int _print_digit(va_list arguments)
{
	int digit = va_arg(arguments, int); /* Extract integer from variable arg */
	int index = 0, is_negative = 0, count; /* Variable initialization */
	char *number_str = malloc(12); /* Buffer for max 12 characters*/
	/* int (-2147483648) */

	if (number_str == NULL) /* Check for failure of malloc */
		exit(98); /* Harsh exit - if malloc failure */

	count = egde_check(digit); /* Handle edge cases (likely 0 value) */
	if (count > 0)
	{
		free(number_str); /* Free memory allocated for number_str */
		return (count); /* Premature return if edge case handled */
	}
	if (digit < 0) /* Negative number handling */
	{
		is_negative = 1;
		digit = -digit; /* Convert to positive for processing */
	}
	for (index = 0; digit != 0; index++)
	{ /* Digit extraction loop (reverse order) */
		number_str[index] = (digit % 10) + '0'; /* + '0' Convert to ASCII */
		digit = digit / 10;
	}
	if (is_negative == 1) /* Add negative sign if needed */
	{
		number_str[index] = '-';
		index++;
	}
	number_str[index] = '\0'; /* Null-terminate string */
	count = index; /* Store length before reversal */

	number_str = rev_string(number_str, count);
	/* Reverse digits to correct order*/

	for (index = 0; number_str[index] != '\0'; index++) /* Output characters */
		_putchar(number_str[index]);

	free(number_str); /* Free memory allocated for number_str */
	return (count); /* return the number of printed characters */
}
