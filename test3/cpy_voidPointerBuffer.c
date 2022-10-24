#include <stdlib.h>
#include <stdio.h> 
#include <stdarg.h>
#include <unistd.h>

/* Works like a charm */

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
}

void *append_buffer(char *buff_add)
{
	/* Check to See what the buffer contains. If it has anything, copy 
	* all their contenst to the main buffer */
	printf("Called Append Buffer()\n");
	char *apd_buff = rtn_buffer();
	int len = 0;

	while (apd_buff[len] != '\0')
	{
		len++;

	}
	printf("Reached End of Buffer. Start Appending\n");
	printf("Returned buffer from rtn_buffer \nBuffer has something of size: %d\n", len);

	/* Check to see if Buff_add is correctly returned from respective functions */
	printf("Address of buff_add : %p\n", buff_add);
	
	/* Check to see whether the buffer was correctly populated */
	int i = 0;
	if (buff_add[i] == '\0')
	{
		printf("Empty Buffer\n");
	}
	else
	{
		printf("Proceeding to while loop\n");
	}

	/* First append main buffer with buff_add */
	while (buff_add[i] != '\0')
	{
		printf("Appending Main Buffer with buffer_add\n");
		apd_buff[len] = buff_add[i];
		len++;
		i++;
	}
	buff_add = apd_buff;
	return(apd_buff);
}

void *write_to_main_buffer(char *main_buffer, char *buff_add)
{
	printf("Called write_to_main_buffer()\n");
	int len = 0;

	while (main_buffer[len] != '\0')
	{
		printf("Getting length :%d\n", len);
		len++;
	}

	int i = 0;
	while(buff_add[i] != '\0')
	{
		printf("Adding to main buffer\n");
		printf("main_buffer[%d] = buff_add[%d]\n", len, i);
		main_buffer[len] = buff_add[i];
		len++;
		i++;
	}
	return(main_buffer);
}


/* Function to print a character */
void *print_char(va_list arg_c)
{
	printf("Called print_char()\n");
	char *char_buffer = malloc(sizeof(char));

	char x = (char)va_arg(arg_c, int);

	int i = 0;
	if (char_buffer[i] == '\0')
	{
		printf("Character buffer Empty\n ... Waiting For append\n");
		char_buffer[i] = x;
		printf("Finished Appending\n");
	}
	return(char_buffer);
}

/* Function to print a string */
void *print_str(va_list arg_str)
{
	printf("Called print_str()\n");
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
}

int _printf(const char *format, ...)
{
	int i = 0, j = 0, len = 0;
	va_list args;
	char *buffer, *str_arg;
	char *main_buffer;
	char *char_buffer, *str_buffer;

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
					buffer[j++] = *(char *)append_buffer(print_char(args));
					break;
				case 's':
					str_arg = append_buffer(print_str(args));
					while(*str_arg)
					{
						buffer[j++] = *str_arg; 
						str_arg++;
					}
					break;
			}
		}
		else
		{
			printf("Printing to buffer[j]\n");
			buffer[j] = format[i];
			j++;
		}
	}
	return (write(1, buffer, j));
}

int main(void)
{

	_printf("Animals like %s like the letter [%c] and the word %s\n", "Pandas", 'x', "Bamboo");
	return(0);
}
