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

#endif /* MAIN_H */
