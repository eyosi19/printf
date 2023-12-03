#include "main.h"


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
	const char *str;
	size_t len;
	char c;

	va_start(args, format);
	count = 0;
	if (!format || !*format)
		return (-1);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == 's')
			{
				str = va_arg(args, const char *);
				if (str != NULL)
				{
					len = strlen(str);
					count += write(1, str, len);
				}
			}
			else if (*format == 'c')
			{
				c = va_arg(args, int);
				count += write(1, &c, 1);
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
