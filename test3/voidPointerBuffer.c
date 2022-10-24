#include <stdlib.h>
#include <stdio.h> 
#include <stdarg.h>
#include <unistd.h>


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
	/* Check to See what the buffer contains. If it has anything, copy 
	* all their contenst to the main buffer */
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
	return(apd_buff);
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
	return(perc_buffer);
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
	return(char_buffer);

	free(char_buffer);
}

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

	int len = 0;
	while (str_buffer[len] != '\0')
	{
		len++;
	}

	int i = 0;
	while(str[i] != '\0')
	{
		str_buffer[len] = str[i];
		len++;
		i++;
	}
	return(str_buffer);
	free(str_buffer);
}

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
					while(*str_arg)
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

int main(void)
{

	_printf("Animals like %s like the letter [%c] and the word %% %s %%\n", "Pandas", 'x', "Bamboo");
	return(0);
}
