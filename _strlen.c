#include "main.h"

/**
 * _strlen - Return the length
 *
 * @str: the string
 *
 * Return: 1
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;
	return (i);
}
