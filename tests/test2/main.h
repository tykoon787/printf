#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct special_characters- Structure containing Special Characters
 * and their respective function calls
 * @s: The special character itself e.g., 'c' || 's'
 * @f: Function Pointer
 */

typedef struct special_characters
{
	char *s;
	int (*f)(va_list);
} spec;/* Specifier */

int _printf(const char *format, ...);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
int _strlen(char *str);
int print_char(va_list arg_c);
int print_str(va_list arg_str);
int (*check_format(const char *format))(va_list);

#endif /* MAIN_H */
