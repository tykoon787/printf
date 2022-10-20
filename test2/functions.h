#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdio.h>

/**
* print_char - prints a character
* @arg_c: character argument
*
* Return: 1 for success
*/

int print_char(va_list arg_c)
{
	char *buff;
	int x; 
	x = va_arg(arg_c, int);
	putchar(x);
	return (1);
}

/**
* print_str - prints string to buffer
* @arg_str: string argument
*
* Return: string length
*/

int print_str(va_list arg_str)
{
	char *str_arg = va_arg(arg_str, char *);
	int x = 0;
	while (str_arg[x] != '\0')
	{
		putchar(str_arg[x++]);
	}
	printf("Len of str: %d\n", x);
	return (x);
}

/**
* format_check - checks format specifier
* @format: specifier
*
* Return: relevant function
*/

int (*check_format(const char *format))(va_list)
{
	int i = 0;

	spec sp[] =
	{
		{"c", print_char},
		{"s", print_str},
		{NULL, NULL}
	};

	for (; sp[i].s != NULL; i++)
	{
		if(*(sp[i].s) == *format)
			break;
	}
	return (sp[i].f);
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
