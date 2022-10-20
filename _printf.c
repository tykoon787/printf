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
	while (format[i] != '\0')
	{
		len++;
		i++;
	}
	buffer = malloc(sizeof(char) * len);
	if (buffer == NULL)
		return (int)(NULL);
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

/**
 * _strcpy - copys a string to given destination
 * @dest: destination
 * @src: str source
 *
 * Return: pointer to buffer
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}

	/* omitted terminating null byte */
	return (dest);
}

/**
 * _putchar - prints out characters
 * @c: character input
 *
 * Return: 0
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - gets length of a string
 * @str: string input
 *
 * Return: length of string
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;

	return (i);
}
