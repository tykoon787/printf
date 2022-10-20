#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	int i = 0, j = 0, len = 0;
	va_list args; 
	/* char x; */
	char *buffer, *str_arg; 

	va_start(args, format);

	/* Get length of format */
	while(format[i] != '\0')
	{
		len++;
		i++;
	}
	printf("Length of format: %d\n", len);
	
	/* Allocate Space to buffer */
	buffer = malloc(sizeof(char) * 100);
	if (buffer == NULL)
		return (-1);

	/* Loop through format to check for format spec */
	for (i = 0; i < len; i++)
	{
		/* Copy the contents of format to buffer */
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					buffer[j] = (char)va_arg(args, int);
					j++;
					break;

				case 's':
					str_arg = va_arg(args, char *);
					strcpy(&buffer[j], str_arg);
					j++;
					break;
			}
		}
		else
		{
			buffer[j] = format[i];
			j++;
		}

		/**if ((format[i] != '%') && (format[i+1] != 'c'))
			buffer[i] = format[i];

		printf("Copying contents to buffer\n");
		switch(format[i])
		{
			case '%':
			if (format[i + 1] == 'c')
			buffer[i] = (char) va_arg(args, int);
			printf("%c\n", x);
		}**/
	}
	/* printf("Copied buffer %d times\n",i); */

	/* Write the buffer to stdout */
	printf("Size of buffer is :%d\n", j);
	write(1, buffer, j);
	putchar('\n');

	return (j);
}

int main(void)
{
	_printf("%c Hello %c World it's %s", 'x', 'b', "Friday");
	return (0);
}
