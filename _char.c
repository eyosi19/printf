#include "main.h"

/**
 * _char - print a char
 *
 * @list: the arguments
 * Description: this function prints a char
 * Return: 1
 */

int _char(va_list list)
{
	char c;

	c = va_arg(list, int);
	_putchar(c);

	return (1);
}
