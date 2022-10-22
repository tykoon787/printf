#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


typedef struct special_character
{
	char *s; 
	char *(*f)(va_list);
} spec_char;

char *(*format_check(const char *format))(va_list)
{
	int i = 0;

	spec_char sp[] = {
		{"s", print_str},
		{NULL, NULL}
	};

	for (; sp[i].s != NULL; i++)
	{
		if (*(sp[i].s) == *format)
			break;
	}
	return (sp[i].f); /* Returns an address to a function */
}

int main(void)
{
	int (*fp)(va_list);
	int i = 0;
	char str[] = "Baby Panda";

	while (*str)
	{
		if (str[i] = '%')
		{
			fp = format_check(str[i]);
		}
	}
}

/**
* print_str - prints string to buffer
* @arg_str: string argument
*
* Return: (1) Always Success
*/

static char* print_str(va_list arg_str, char *buffer)
{
	char *str_arg = va_arg(arg_str, char *);
	int x = 0;

	while (str_arg[x] != '\0')
	{
		buffer[x] = str_arg[x];
		putchar(str_arg[x++]);
	}
	buffer = malloc(sizeof(char) * x);
	return (buffer);
}

int _printf(const char *format, ...)
{
	int i = 0;
	char *buffer;
	va_list args;
	char (*f)(va_list);

	while (*format)
	{
		if (format[i] == '%')
		{
			f = format_check(&format[i+1]);
			buffer = f(args);
		}
	}
}
