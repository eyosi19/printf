#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_s(char *str);
int print_c(char c);
int print_percent(void);
int _strlen(char *str);

#endif
