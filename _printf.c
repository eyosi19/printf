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
				count += write(1, format, 1);
			}
		}
		format++;
	}

	va_end(list);
	return (count);
}
