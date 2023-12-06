#include "main.h"

/**
 * _unsigned - prints unsigned integer
 *
 * @list: the argument
 *
 * Return: the integer
 */

int _unsigned(va_list list)
{
	unsigned int n = va_arg(list, int);
	unsigned int num = n;
	unsigned int last;
	unsigned int ex = 1;
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num / 10 != 0)
	{
		ex *= 10;
		num /= 10;
	}

	num = n;

	while (ex > 0)
	{
		last = num / ex;
		_putchar(last + '0');
		num = num - (last * ex);
		ex /= 10;
		i++;
	}

	return (i);

}
