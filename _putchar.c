#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @ch: character to be printed
 *
 * Return: 1 on success
 *         -1 on error and errno is set
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}
