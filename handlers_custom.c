#include "main.h"

int count; /*global variable declaration*/

/**
 * binary_handler - handles unsigned int to binary specifier
 * @ap: a va_list containing the unsigned int
 *
 * Return: the digit count in binary
 * Author: Gamachu AD
 */
int binary_handler(va_list ap)
{
	int digit = 0;
	unsigned int n = va_arg(ap, int);

	if (n == 0)
		return (_putchar('0'));
	digit = print_binary(n);

	return (digit);
}


/**
 * print_binary - converts an int to binary and prints it
 * @n: the number to be converted
 *
 */
int print_binary(unsigned int n)
{
	count = 0; /*initialize the global variable*/

	if (n == 0)
	{
		return (1);
	}
	print_binary(n >> 1);
	count += _putchar('0' + (n % 2));
	return (count);
}
