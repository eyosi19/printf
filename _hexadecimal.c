#include "main.h"

/**
 * _hexadecimal - converts unsigned int to octal
 *
 * @list: the argument
 *
 * Return: count
 */

int _hexadecimal(va_list list)
{
	int i, count = 0;
	int *arr;
	unsigned int n = va_arg(list, unsigned int);
	unsigned int t = n;

	while (n / 16 != 0)
	{
		n /= 16;
		count++;
	}
	count++;
	
	arr = malloc(count * sizeof(int));

	for (i = 0; i < count; i++)
	{
		arr[i] = t % 16;
		t /= 16;
	}

	for (i = count - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
		{
			arr[i] = arr[i] + 39;
		}
		_putchar(arr[i] + '0');
	}

	free(arr);

	return (count);
}
