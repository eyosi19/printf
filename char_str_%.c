#include "main.h"

/**
 * print_char - print char
 *
 * @c: the char
 *
 * Return: count
 */

int print_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - custom printf
 *
 * @format: the first argument
 *
 * Return: count
 */

int _printf(const char *format, ...)
{
	int count;
	va_list args;
	char *str;

	count = 0;

	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			count += write(1, format, 1);
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				count += print_char(va_arg(args, int));
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				count += write(1, str, strlen(str));
			}
			else if (*format == '%')
			{
				count += write(1, "%", 1);
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
