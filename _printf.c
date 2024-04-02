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
	int char_num = 0; /*Stores total characters written*/

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			char_num += write(STDOUT_FILENO, format, 1);
		}
		else
		{
			char_num += parse_format(format, ap);
			format++;
		}
		format++;
	}
	va_end(ap);
	return (char_num);
}

/**
 * parse_format - parses the format string for format specifiers
 * @fm: pointer to format string
 * @ap: variable argument list
 *
 * Return: the number of chars written
 */
int parse_format(const char *fm, va_list ap)
{
	int count = 0;

	/*check if the next char is a valid format specifier*/
	fm++;
	switch (*fm)
	{
	case 'c':
		count += _putchar(va_arg(ap, int));
		break;
	case 's':
		count += print_string(va_arg(ap, char *));
		break;
	case '%':
		count += _putchar('%');
		break;
	default:
		count += _putchar(*fm);
	}
	return (count);
}

/**
 * _putchar - prints a character
 * @ch: character to be printed
 *
 * Return: 1 on success
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * print_string - prints a string
 * @str: pointer to the string
 *
 * Return: the length of the string
 */
int print_string(char *str)
{
	int count = 0;

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}
	return (count);
}
