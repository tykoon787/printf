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
	snprintf(buffer, BUFFSIZE, "%s", "Baby Panda ");
	return (buffer);
}

void *append_buffer(char *buff_add, char *str)
{
	
	

	/* Check to See what the buffer contains. If it has anything, copy 
	* all their contenst to the main buffer */
	char *apd_buff = rtn_buffer();
	int len = 0;

	while (apd_buff[len] != '\0')
	{
		len++;

	}
	printf("Reached End of Buffer. Start Appending\n");

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

	/* Then append buffer with str */
	i = 0;
	while (str[i] != '\0')
	{
		apd_buff[len] = str[i];
		len++;
		i++;
	}
	buff_add = apd_buff;
	return(apd_buff);
}

/* Function to print a character */
void *print_char(va_list arg_c)
{
	printf("Looking for character\n");
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

int _printf(const char *format, ...)
{
	int i = 0, j = 0, len = 0;
	va_list args;
	char *buffer, *str_arg;
	char *main_buffer;

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
					printf("Character Found\n");
					main_buffer = append_buffer(print_char(args), "");
					printf("End of find\n");
			}
		}
		else
		{
			buffer[j] = format[i];
			j++;
		}
	}
	return (write(1, main_buffer, j));
}




int main(void)
{

	_printf("I am %cot your brother\n", 'N');
	return(0);
}
