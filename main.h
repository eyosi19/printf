#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * struct print - the name of the struct
 *
 * @specifier: the specifier
 *
 * @func: the function
 */

typedef struct print
{
	char *specifier;
	int (*func)();
} pair;

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *str);
int _strlen_const(const char *str);
int _string(va_list list);
int _char(va_list list);
int _percent(void);
int _integer(va_list list);
int _decimal(va_list list);

#endif
