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
