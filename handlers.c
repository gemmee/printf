#include "main.h"

/**
 * print_integer - prints an integer
 * @n: integer to be printed
 *
 * Return: number of digits written
 * Author: Gamachu AD
 */
int print_integer(int n)
{
	static int digit = 0;

	if (n == 0 && digit == 0)
		return (_putchar(48));

	if (n < 0)
	{
		digit += _putchar('-');
		n = -n;
	}
	if (n == 0)
		return (1);

	print_integer(n / 10);
	digit += _putchar(n % 10 + 48);

	return (digit);
}
