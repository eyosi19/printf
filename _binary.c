#include "main.h"

/**
 * _binary - converts unsinged int to binary
 * @list: list of arguments passed to _printf
 *
 * Return: 1
 */


int _binary(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int binary[64];
	int i = 0;
	int j;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		binary[i] = num % 2;
		num = num / 2;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		_putchar('0' + binary[j]);
	}

	return (i);
}
