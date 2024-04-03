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
	ret = print_number(nu);

	if (ret == -1)
		return (-1);
	count += ret;

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
	int count = 1;
	int num, digit, arg, ret, exp = 1;

	if (n < 0)
	{
		ret = _putchar('-');
		if (ret == -1)
			return (-1);
		n = -n;
		count++;
	}
	num = n;
	arg = n % 10;
	n /= 10;
	if (num > 0)
	{
		while (num / 10)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp)
		{
			digit = num / exp;
			ret = _putchar(digit + '0');
			if (ret == -1)
				return (-1);
			num = num % exp;
			exp = exp / 10;
			count += ret;
		}
	}
	_putchar(arg + '0');
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
