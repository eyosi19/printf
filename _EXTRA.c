#include "main.h"

/**
 * _EXTRA - converts unsigned int to octal
 *
 * @list: the argument
 *
 * Return: count
 */

int _EXTRA(unsigned int n)
{
	int i, count = 0;
	int *arr;
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
			arr[i] = arr[i] + 7;
		}
		_putchar(arr[i] + '0');
	}

	free(arr);

	return (count);
}
