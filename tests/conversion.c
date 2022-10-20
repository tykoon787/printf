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

int main(void)
{
	_printf("Hello %c World %c and %s", 'x', 'b', "Panda");
	return (0);
}
