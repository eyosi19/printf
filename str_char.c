#include "main.h"

/**
 * _printf - my own printf function
 *
 * @format: the format
 *
 * Return: count
 */

int _printf(const char *format, ...)
{
	int count;
	va_list args;

	count = 0;

	va_start(args, format);

	if (!*format || !format)
	{
		return (-1);
	}

	while(*format)
	{
		if (*format == '%')
		{
			format++;

			switch(*format)
			{
				case 's':
					count += write(1, va_arg(args, const char*), sizeof(char));
					break;
				case 'c':
					{
						char c = (char)va_arg(args, int);
						count += write(1, &c, sizeof(char));
					}
					break;
				default:
					return (-1);
			}
		}
		else
		{
			count += write(1, format, sizeof(char));
		}

		format++;

		va_end(args);
		return (count);
}
