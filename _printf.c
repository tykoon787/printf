#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf- Implementation of `printf()`
 * @format: User Input
 *
 * Return: Number of bytes written to `stdout`
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
				case 'c':
					buffer[j] = (char) va_arg(args, int);
					j++;
					break;
				case 's':
					str_arg = va_arg(args, char *);
					_strcpy(&buffer[j], str_arg);
					j = j + _strlen(str_arg);
					break;
				case '%':
					buffer[j] = format[i];
					j++;
					break;
			}
		}
		else
		{
			buffer[j] = format[i];
			j++;
		}
	}
	return (write(1, buffer, j));
}
