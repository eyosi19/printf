#include <stdio.h>
#include "main.h"

/**
 * print_str - prints a string
 *
 * @str: the string
 *
 * Return: count
 */

int print_str(char *str)
{
	int count;
	int len;

	len = 0;
	count = 0;

	while (str[len] != '\0')
		len++;

	count += write(1, str, len);

	return (count);
}

/**
 * print_char - print a char
 *
 * @c: the char
 *
 * Return: return the char
 */

int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_percent - print a percent sign
 *
 * Return: the printed value with percent sign
 */

int print_percent(void)
{
	return (write(1, "%", 1));
}

/**
 * _printf - our printf function
 *
 * @format: the first argument
 *
 * Return: count
 */

int _printf(const char *format, ...)
{
	int count;
	va_list args;

	count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\n')
				break;
			if (*format == 'c')
			{
				count += print_char(va_arg(args, int));
			}
			if (*format == 's')
			{
				count += print_str(va_arg(args, char *));
			}
			if (*format == '%')
			{
				count += print_percent();
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
