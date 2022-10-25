#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include "functions.h"
#include "functions2.h"

/**
 * _printf- Function that implements the use of `printf`
 * @format: Input string
 *
 * Return: Number of words printed by `_printf`
 */

int _printf(const char *format, ...)
{
	int i = 0, j = 0, len = 0;
	va_list args;
	char *buffer, *str_arg;

	va_start(args, format);
	while (format[len] != '\0')
		len++;
	buffer = malloc(sizeof(char) * len);
	if (buffer == NULL)
		return (-1);
	for (i = 0; i < len; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case '%':
					buffer[j++] = *(char *)append_buffer(print_perc(args));
					break;
				case 'c':
					buffer[j++] = *(char *)append_buffer(print_char(args));
					break;
				case 's':
					str_arg = append_buffer(print_str(args));
					while (*str_arg)
					{
						buffer[j++] = *str_arg++;
					}
					break;
			}
		}
		else
			buffer[j++] = format[i];
	}
	return (write(1, buffer, j));
	free(buffer);
}
