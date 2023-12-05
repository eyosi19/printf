#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *str);
int _strlen_const(const cahr *str);
int _string(va_list list);
int _char(va_list list);
int _percent(void);

#endif
