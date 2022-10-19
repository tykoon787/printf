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
	printf("Length of format: %d\n", len);
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
		printf("Loop number %d\n",i);
		if (format[i] == '%')
		{
			switch(format[i + 1])
			{
				case 'c':
					buffer[i] = (char) va_arg(args, int);
					printf("%c\n", x);
					printf("Character\n");
					i++;
					count++;
					break;
				case 's':
					str_arg = va_arg(args, char *);
					strcpy(&buffer[i], str_arg);
					printf("this is a string\n");
					i++;
					count++;
					break;
				case 'd':
					buffer[i] = va_arg(args, int);
					// Buffer stores int as a char,
					// Conversion needed during output
					printf("This is a decimal value\n");
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
		printf("Size of buffer is %d\n", count);
	}
	printf("Copied buffer %d times\n",i);
	
	/* Get buffer length */
	int buff_len = 0;
	int j = 0;

	while(*buffer)
	{
		buff_len++;
		buffer++;
		
	}
	buffer = cpy_buffer;
	
	printf("Length of Buffer %d\n", buff_len);

	/* Write the buffer to stdout */
	/* printf("Size of buffer is :%d\n", i+1); */
	/* printf("%d\n", (int) strlen(str_arg)); */
	printf("Printed :%d bytes\n", (int) write(1, buffer, count + strlen(str_arg) + 1));
	putchar('\n');

	return (returnValue);
}

int main(void)
{
	_printf("Hello %c World %c and %s", 'x', 'b', "Panda");
	return (0);
}
