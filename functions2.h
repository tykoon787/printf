#ifndef FUNCTIONS2_H
#define FUNCTIONS2_H

#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
* print_str - prints string to buffer
* @arg_str: string argument
*
* Return: Buffer Address storing the string
*/

void *print_str(va_list arg_str)
{
	char *str_buffer = malloc(BUFFSIZE);

	char *str = va_arg(arg_str, char *);

	int len = 0, i = 0;

	while (str_buffer[len] != '\0')
	{
		len++;
	}


	while (str[i] != '\0')
	{
		str_buffer[len] = str[i];
		len++;
		i++;
	}
	return (str_buffer);
	free(str_buffer);
}

void *print_int(va_list arg_int)
{
	char *int_buffer = malloc(sizeof(int));	
	char x = va_arg(arg_int, int);

	int i = 0; 

	if (int_buffer[i] == '\0')
	{
		int_buffer[i] = x;
	}
	return (int_buffer);
	free(int_buffer);
}

#endif /* FUNCTIONS2_H */
