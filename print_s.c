#include "main.h"


int print_s(char *str)
{
	int i, count = 0;
	
	for (i = 0; str[i] != '\0'; i++)
	{
		if (_putchar(str[i]) >= 0)
		{
			count++;
		}
		else
		{
			return (-1);
		}
	}
	return (count);
}
