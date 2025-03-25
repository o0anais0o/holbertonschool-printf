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
	if (digit == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (digit == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	return (0);
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

	for (index = 0, index2 = length; index < index2; index++, index2--)
	{
		reverse = number_str[index];
		number_str[index] = number_str[index2];
		number_str[index2] = reverse;
	}
	return (number_str);
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
	int digit = va_arg(arguments, int);
	int index = 0, is_negative = 0, count;
	char *number_str = malloc(12); /* int : -2147483648 to 2147483647 + '\0' */

	if (number_str == NULL) /* Checking for allocation fail */
		exit(98); /* Exit the program if allocation failure */

	count = egde_check(digit); /* Checking for edge cases */
	if (count > 0) /* If an edge case was found */
	{
		free(number_str);
		return (count);
	}
	if (digit < 0)
	{
		is_negative = 1;
		digit = -digit; /* Remove the '-' symbol to put digits in a string */
	}
	for (index = 0; digit != 0; index++) /* Convert the digit into a string */
	{
		number_str[index] = (digit % 10) + '0'; /* Save the last digit */
		digit = digit / 10; /* Truncate the last digit */
	}
	if (is_negative == 1)
	{
		number_str[index] = '-'; /* Put back the '-' symbol */
		index++;
	}
	number_str[index] = '\0'; /* Put the '\0' at the end of the string */
	count = index - 1; /* The length of the string and bytes count */

	number_str = rev_string(number_str, count); /* Reverse the string */

	for (index = 0; number_str[index] != '\0'; index++) /* Print the string */
		write(1, &number_str[index], 1);

	free(number_str);
	return (count);
}