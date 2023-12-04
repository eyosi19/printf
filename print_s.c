#include "main.h"


/**
 * print_s - print a string
 *
 * @str: the string
 *
 * Return: string
 */

int print_s(char *str)
{
	int i, len;

	if (str == NULL)
	{
		str = "(null)";
	}

	len = _strlen(str);

	for (i = 0; i < len; i++)
	{
		_putchar(str[i]);
	}

	return (len);
}
