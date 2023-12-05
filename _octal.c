#include "main.h"

/**
 * _octal - converts unsigned int to octal
 *
 * @list: the argument
 *
 * Return: count
 */

int _octal(va_list list)
{
	int i, count = 0;
	int *arr;
	unsigned int n = va_arg(list, unsigned int);
	unsigned int t = n;

	while (n / 8 != 0)
	{
		n /= 8;
		count++;
	}
	count++;
	
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = t % 8;
		t /= 8;
	}

	for (i = count - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}

	free(arr);

	return (count);
}
