#include "main.h"

/**
 * print_number - prints any number to base 10
 * @n: number to be printed in base 10
 *
 * Return: number of digits printed
 */
int print_number(unsigned int n)
{
	int ret;
	unsigned int num = n;
	static int count;

	if (num / 10)
		print_number(num / 10);
	ret = _putchar('0' + num % 10);
	if (ret == -1)
		return (ret);
	count += ret;
	return (count);
}

/**
 * count_digits - counts how digits are in the number
 * @n: the number
 *
 * Return: the count
 */
int count_digits(unsigned int n)
{
	int count = 0;

	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}
