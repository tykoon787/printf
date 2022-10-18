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
	char *buffer; 

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

	/* Loop through format to check for format spec */
	for (; i < len; i++)
	{
		/* Copy the contents of format to buffer */
		buffer[i] = format[i];

		printf("Copying contents to buffer\n");
		switch(format[i])
		{
			case '%':
			if (format[i + 1] == 'c')
			buffer[i] = (char) va_arg(args, int);
			printf("%c\n", x);
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
	_printf("%c Hello %c World", 'x', 'b');
	return (0);
}
