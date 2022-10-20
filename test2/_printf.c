#include <stdlib.h>
#include <stdarg.h>
#include "functions.h"
#include "main.h"

/**
 * _printf- Function that implements the use of `printf`
 * @format: Input string
 *
 * Return: Number of words printed by `_printf`
 */

int _printf(const char *format, ...)
{
	int (*fp)(va_list);
	int word_counter = 0, i = 0;
	va_list args;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			fp = format_check(&format[i]);
			word_counter = word_counter + fp(args);
			i++;
			continue;
		}
		else
		{
			_putchar(format[i]);
			word_counter++;
		}
	i++;
	}
	va_end(args);
	word_counter = word_counter - 1;
	return (word_counter);
}
