#include <stdio.h>
#include "../main.h"

/**
 * main  - Entry point
 * Return: Always 0
 */
int main(void)
{
	int len1, len2;

	len1 = _printf("Gamachu.");
	_putchar('\n');
	len2 = printf("Gamachu.");
	putchar('\n');
	printf("len1 = %d\vlen2 = %d\n", len1, len2);

	_printf("My name is %s. What's yours?", "Gamachu");
	putchar('\n');

	_printf("Hello %c%c%c%c%c%c%c", 'G', 'a', 'm', 'a', 'c', 'h', 'u');
	putchar('\n');

	_printf("Are you 100%% sure?\%");
	putchar(10);

	return (0);
}
