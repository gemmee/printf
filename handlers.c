#include "main.h"

/**
 * character_handler - handles character specifier
 * @ap: argument list containing the char to pritn as the next element
 *
 * Return: number of bytes printed
 */
int character_handler(va_list ap)
{
	char c = va_arg(ap, int);

	return (_putchar(c));
}

/**
 * string_handler - handles string specifier
 * @ap: argument list containing the string to print
 *
 * Return: number of chars printed on success
 *         -1 on failure
 */
int string_handler(va_list ap)
{
	char *str = va_arg(ap, char *);
	int ret, count = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		ret = _putchar(*str);
		if (ret == -1)
			return (-1);
		count += ret;
		str++;
	}

	return (count);
}

/**
 * decimal_handler - handles decimal specifier
 * @ap: the va_list containing the decimal
 *
 * Return: number of digits written on success
 *         -1 on failure
 */
int decimal_handler(va_list ap)
{
	int n = va_arg(ap, int);
	int ret, count = 0;
	unsigned int nu; /*this is needed to be able to store INT_MIN as positive*/

	/*Handle negative numbers*/
	if (n < 0)
	{
		ret = _putchar('-');
		if (ret == -1)
			return (-1);

		count += ret;
		nu = -n;
	}
	else if (n == 0)
	{
		return (_putchar('0'));
	}
	else
	{
		nu = n;
	}
	count += count_digits(nu);
	print_number(nu);

	return (count);
}

/**
 * integer_handler - handles %i specifier
 * @ap: a va_list containing integer
 *
 * Return: the number of char printed
 *        -1 on error
 */
int integer_handler(va_list ap)
{
	int n = va_arg(ap, int);
	int count = 0;
	int digit, ret, exp = 1;
	unsigned int num, m;

	if (n == 0)
		return (_putchar('0'));
	if (n < 0)
	{
		ret = _putchar('-');
		if (ret == -1)
			return (-1);
		num = -n;
		count += ret;
	}
	else
	{
		num = n;
	}
	m = num;
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		while (exp)
		{
			digit = m / exp;
			ret = _putchar(digit + '0');
			if (ret == -1)
				return (-1);
			count += ret;
			m = m - (digit * exp);
			exp = exp / 10;
		}
	}

	return (count);
}

/**
 * percent_handler - handles percent(%%) specifier
 * @ap: argument list
 *
 * Return: 1 on success, -1 on failure
 */
int percent_handler(va_list ap)
{
	int ret = _putchar('%');
	(void)ap;

	return (ret);
}
