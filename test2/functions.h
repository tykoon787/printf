#include <stdarg.h>
#include <stdio.h>

/* Functions go here */

/* Definitions */
int print_char(va_list arg_c)
{
	char *buff;
	int x; 
	x = va_arg(arg_c, int);
	putchar(x);
	return (1);
}


