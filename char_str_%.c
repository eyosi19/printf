#include "main.h"
/**
 * _printf - custom printf
 *
 * @format: the first argument
 *
 * Return: count
 */

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char *str;

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
				char c = va_arg(args, int);

				count += write(1, &c, 1);
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
