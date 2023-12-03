#include "main.h"
#include <stdio.h>
/**
 * write_char - write char
 *
 * @c: the char
 *
 * Return: return the char
 */

int write_char(char c)
{
	return (write(1, &c, sizeof(char)));
}
/**
 * write_str - write a string
 *
 * @str: the string
 *
 * Return: return the string
 */

int write_str(const char *str)
{
	size_t len;
	const char *null_str;

	len = 0;

	if (str != NULL)
	{
		while (str[len] != '\0')
		{
			len++;
		}
		return (write(1, str, len));
	}
	else
	{
		null_str = "(null)";
		return (write(1, null_str, 6));
	}
}

/**
 * write_percent - write a percent sign
 *
 * Return: return %
 */

int write_percent(void)
{
	return (write(1, "%", sizeof(char)));
}


/**
 * _printf - printf function
 *
 * @format: the format specifier
 *
 * Return: count
 */

int _printf(const char *format, ...)
{
	int count;
	va_list args;
	char c;
	const char *str;

	va_start(args, format);
	count = 0;
	if (!format || !*format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 's')
			{
				str = va_arg(args, const char *);
				count += write_str(str);
			}
			else if (*format == 'c')
			{
				c =	(char)va_arg(args, int);
				count += write_char(c);
			}
			else if (*format == '%')
				count += write_percent();
			else
			{
				count += write(1, format - 1, 2 * sizeof(char));
			}
		}
		else
			count += write(1, format, sizeof(char));
		format++;
	}
	va_end(args);
	return (count);
}
