#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * rtn_buffer- Function that returns buffer address
 *
 * Return: Buffer address
 */

#define BUFFSIZE 1024
void *rtn_buffer()
{

	char *buffer = malloc(BUFFSIZE);

	return (buffer);
	free(buffer);
}

/**
 * append_buffer- Function that appends the buffer
 * @buff_add: Buffer address to be appended
 *
 * Return: Appended Buffer Address
 */

void *append_buffer(char *buff_add)
{
	/* Check to See what the buffer contains. If it has anything, copy */
	/* all their contenst to the main buffer */
	char *apd_buff = rtn_buffer();
	int len = 0;

	while (apd_buff[len] != '\0')
	{
		len++;

	}

	/* Check to see whether the buffer was correctly populated */
	int i = 0;
	/* First append main buffer with buff_add */
	while (buff_add[i] != '\0')
	{
		apd_buff[len] = buff_add[i];
		len++;
		i++;
	}
	buff_add = apd_buff;
	return (apd_buff);
	free(apd_buff);
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
 * print_perc- Prints percentage sign `%`
 * @arg_perc: Percentage Argument
 * Return: Buffer Address that has % sign
 */

void *print_perc(__attribute__((unused))va_list arg_perc)
{
	char *perc_buffer = malloc(BUFFSIZE);

	int i = 0;

	if (perc_buffer[i] == '\0')
	{
		perc_buffer[i] = '%';
	}
	return (perc_buffer);
	free(perc_buffer);
}

/**
* print_char - prints a character
* @arg_c: character argument
*
* Return: Buffer address that stores the character
*/

void *print_char(va_list arg_c)
{
	char *char_buffer = malloc(sizeof(char));

	char x = (char)va_arg(arg_c, int);

	int i = 0;

	if (char_buffer[i] == '\0')
	{
		char_buffer[i] = x;
	}
	return (char_buffer);
	free(char_buffer);
}
#endif /* FUNCTIONS_H */
