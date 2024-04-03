#include "main.h"

/**
 * _printf - a custom printf function
 * @format: the format string
 *
 * Return: the number of characters printed
 * Author: Gamachu AD
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int ret, count = 0;

	if (!format || (*format == '%' && *(format + 1) == '\0'))
		return (-1);

	va_start(ap, format);

	ret = process_format(format, ap);
	if (ret == -1)
		return (-1);
	count += ret;

	va_end(ap);
	return (count);
}

/**
 * process_format - processes the format string
 * @format: the format string
 * @ap: the argument list
 *
 * Return: the count of letters written on success
 *         -1 on failure
 */
int process_format(const char *format, va_list ap)
{
	int ret, count = 0;
	int (*f)(va_list) = NULL;

	while (*format)
	{
		if (*format != '%')
		{
			ret = _putchar(*format);
		}
		else if (*format == '%' && *(format + 1) == '%')
		{
			format++;
			ret = _putchar('%');
		}
		else
		{
			format++;
			if (*(format) == '\0')
				return (-1);
			f = get_specifier(format);
			if (!f)
			{
				ret = _putchar(*(format - 1));
				if (ret == -1)
					return (-1);
				count += ret;
				ret = _putchar(*format);
			}
			else
			{
				ret = f(ap);
			}
		}
		if (ret == -1)
			return (-1);
		count += ret;
		format++;
	}
	return (count);
}

