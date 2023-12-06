#include "main.h"

/**
 * _printf - our own printf
 *
 * @format: the specifier
 *
 * Return: int
 */

int _printf(const char *format, ...)
{
	pair y[] = {
		{"%c", _char}, {"%s", _string}, {"%%", _percent},
		{"%i", _integer}, {"%d", _decimal}, {"%b", _binary},
		{"%i", _integer}, {"%d", _decimal}, {"%u", _unsigned},
		{"%o", _octal}, {"%x", _hexadecimal}, {"%X", _HEXADECIMAL},
	};

	int k;
	int i = 0, len = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}

loop:
	while (format[i] != '\0')
	{
		k = 11;

		while (k >= 0)
		{
			if (y[k].specifier[0] == format[i] && y[k].specifier[1] == format[i + 1])
			{
				len = len + y[k].func(args);
				i += 2;
				goto loop;
			}
			k--;
		}
		_putchar(format[i]);
		i++;
		len++;
	}

	va_end(args);
	return (len);
}
