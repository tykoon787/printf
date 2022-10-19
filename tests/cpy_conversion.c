#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	int i = 0, returnValue = 22, size = 0, len = 0;
	va_list args; 
	char x;
	char *buffer, *str_arg; 

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
	buffer = malloc(sizeof(char) * len);
	if (buffer == NULL)
		return (-1);

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
					break;
				case 's':
					str_arg = va_arg(args, char *);
					strcpy(&buffer[i], str_arg);
					printf("This is a string\n");
					i++;
					break;
				case 'd':
					buffer[i] = va_arg(args, int);
					// Buffer stores int as a char,
					// Conversion needed during output
					printf("This is a decimal value\n");
					i++;
					break;
			}
		}
		else
		{
			buffer[i] = format[i];
		}
	}
	printf("Copied buffer %d times\n",i);

	/* Write the buffer to stdout */
	printf("Size of buffer is :%d\n", (int)sizeof(buffer));
	write(1, buffer, len+1);
	putchar('\n');

	return (returnValue);
}

int main(void)
{
	_printf("%c Hello %c W %sorld %d", 'x',"Baby Panda", 'b', 33);
	return (0);
}
