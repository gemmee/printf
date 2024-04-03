#include <stdio.h>
#include <stdlib.h>
#include "../../main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;

	len = _printf("%b - %b = %b\n", 2048, 1024, 1024);
	len2 = printf("100000000000 - 10000000000 = 10000000000\n");
	fflush(stdout);
	if (len != len2)
	{
		printf("len =%d\nlen2=%d\n",len, len2);
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
