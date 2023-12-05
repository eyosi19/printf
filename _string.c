#include "main.h"

/**
 * _string - prints string
 *
 * @list: arguments
 *
 * Return: 1
 */

int _string(va_list list)
{
	char *str;
	int len, i;

	str = va_arg(list, char *);

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
