#include "main.h"
/**
 * write_char - write char
 *
 * @c: the char
 *
 * Return: return the char
 */

int write_char(int c)
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
	int count;

	count = 0;
		while (*str)
		{
			write_char((int)*str);
			count++;
			str++;
		}
		return (count);
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
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
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
