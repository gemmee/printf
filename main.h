#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int parse_format(const char *fm, va_list ap);
int _putchar(char ch);
int print_string(char *str);
int print_integer(int n);


#endif /*MAIN_H*/
