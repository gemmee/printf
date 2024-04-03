#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

/**
 * struct specifiers - structure to find the correct function and specifiers
 * @letter: specifier conversion
 * @handle: function
 *
 */
typedef struct specifiers
{
	char *letter;
	int (*handle)(va_list);
} specifier_t;

int _printf(const char *format, ...);
int _putchar(char ch);
int process_format(const char *frmt, va_list ap);

int character_handler(va_list ap);
int string_handler(va_list ap);
int percent_handler(va_list ap);
int (*get_specifier(const char *spec))(va_list);
int decimal_handler(va_list ap);
int integer_handler(va_list ap);
int print_number(unsigned int n);
int count_digits(unsigned int n);

#endif /*MAIN_H*/
