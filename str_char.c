#include "main.h"

/**
 * write_char - write char
 *
 * @c: the char
 *
 * Return: return the char
 */

int write_char(char c)
{
	return (write(1, &c, 1));
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

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (write(1, str, len));
}

/**
 * write_percent - write a percent sign
 *
 * Return: return %
 */

int write_percent(void)
{
	return (write(1, "%", 1));
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
				count += write_str(va_arg(args, char *));
			}
			else if (*format == 'c')
			{
				count += write_char(va_arg(args, int));
			}
			else if (*format == '%')
			{
				count += write_percent();
			}
			else
			{
				count += write(1, format - 1, 2);
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
