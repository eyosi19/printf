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
	int i, length;

	if (str == NULL)
	{
		str = "(null)";
		length = _strlen(str);

		for (i = 0; i < length; i++)
		{
			_putchar(str[i]);
		}
		return (length);
	}
	else
	{
		length = _strlen(str);

		for (i = 0; i < length; i++)
		{
			_putchar(str[i]);
		}
		return (length);
	}
}
