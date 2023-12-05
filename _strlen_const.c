#include "main.h"

/**
 * _strlen_const - Return the const length
 *
 * @str: the string
 *
 * Return: 1
 */

int _strlen_const(const char *str)
{
        int i;

        for (i = 0; str[i] != 0; i++)
                ;
        return (i);
}


