#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	int i = 0, count = 0, returnValue = 22, size = 0, len = 0;
	va_list args; 
	char x;
	char *buffer, *str_arg, *cpy_buffer; 
	

	va_start(args, format);

	/* Get length of format */
	while(format[size] != '\0')
	{
		len++;
		size++;
	}
	size = 0;
	
	/* Allocate Space to buffer */
	buffer = malloc(sizeof(char) * 1000);
	if (buffer == NULL)
	{
		return (-1);
	}
	else
	{
		cpy_buffer = buffer;
	}

	for (; i < len; i++)
	{
		if (format[i] == '%')
		{
			switch(format[i + 1])
			{
				case 'c':
					buffer[i] = (char) va_arg(args, int);
					i++;
					count++;
					break;
				case 's':
					str_arg = va_arg(args, char *);
					strcpy(&buffer[i], str_arg);
					i++;
					count++;
					break;
				case 'd':
					buffer[i] = va_arg(args, int);
					 /* Buffer stores int as a char, */
					 /* Conversion needed during output */
					i++;
					count++;
					break;
			}
		}
		else
		{
			buffer[i] = format[i];
			count++;
		}
	}
	
	

	/* Write the buffer to stdout */
	returnValue = (int) write(1, buffer, count + strlen(str_arg) + 1);

	return (returnValue);
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
/**
 * main - entry point
 *
 * Return: Number of characters printed
 */

int main(void)
{
	char *ptr;
	char buff[100];

	/* test _strcpy */
	ptr = _strcpy(buff, "grand rapids");

	_printf("%s", ptr);

	_printf("\n");

	/* test _strlen */
	printf("length of world is %d\n", _strlen("world"));

	/* test _putchar */

	_putchar('b');
	_putchar('\n');

	_printf("Hello %c World %c and %s", 'x', 'b', "Panda");
	return (0);
}
