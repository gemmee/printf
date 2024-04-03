#include "main.h"

/**
 * get_specifier - determines which print function to use
 * @spec: the specifier that identifies the type of variable to print
 *
 * Return: a pointer to a function that takes va_list as parameter
 *         NULL if it can't find the specifier
 * Author: Gamachu AD
 */
int (*get_specifier(const char *spec))(va_list)
{
	int i;

	specifier_t types[] = {
		{"c", character_handler},
		{"s", string_handler},
		{"%", percent_handler},
		{"d", decimal_handler},
		{"i", integer_handler},
		{"b", binary_handler},
		{NULL, NULL}
	};

	for (i = 0; types[i].letter; i++)
	{
		if (*spec == types[i].letter[0])
			return (types[i].handle);
	}
	return (NULL);
}
