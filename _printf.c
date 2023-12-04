#include "main.h"

/**
 * _printf - custom print
 *
 * @format: format specifier
 *
 * Return: count;
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list list;

	if (format == NULL)
		return (-1);
	va_start(list, format);
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
				return (-1);
			if (*format == 's')
			{
				count += print_s(va_arg(list, char *));
			}
			else if (*format == 'c')
			{
				count += print_c(va_arg(list, int));
			}
			else if (*format == '%')
			{
				count += print_percent();
			}
			else
			{
				va_end(list);
				return (-1);
			}
		}
		format++;
	}
	va_end(list);
	return (count);
}
