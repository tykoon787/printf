#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdarg.h>
#include <unistd.h>
#include "functions.h"

/* Declarations */
int print_char(va_list c);
int (*check_format(const char *format))(va_list);

/*  */
/*  Definitions */ 
/* int print_char(va_list arg_c) */
/* { */
/* 	char *buff; */
/* 	int x;  */
/* 	x = va_arg(arg_c, int); */
/* 	putchar(x); */
/* 	return (1); */
/* } */
/*  */
int print_str(va_list arg_str)
{
	char *str_arg = va_arg(arg_str, char *);
	int x = 0;
	while (str_arg[x] != '\0')
	{
		putchar(str_arg[x++]);
	}
	printf("Len of str: %d\n", x);
	return(x);
}

/* Structs */
typedef struct special_characters
{
	char *s; 
	int (*f)(va_list);
}spec; /* Specifier */

int (*check_format(const char *format))(va_list)
{

	int i = 0;
	/* Struct Array */
	spec sp[] = 
	{
		{"c", print_char},		
		{"s", print_str}, 
		{NULL, NULL}
	};

	for (; sp[i].s != NULL; i++)
	{
		if(*(sp[i].s) == *format)
			break;
	}
	return (sp[i].f);
}

int _printf(const char *format, ...)
{
	int (*fp)(va_list);
	int returnValue, i = 0;
	int counter = 0;
	va_list args;
	
	va_start(args, format);
	while (format[i] != '\0')
	{
		printf("Value of Counter: %d\n", counter);
		if (format[i] == '%')
		{
			i++;
			fp = check_format(&format[i]);				
			counter = counter + fp(args);
			i++;
			continue;
		}
		else
		{
			putchar(format[i]);
			counter++;
		}
	i++;
	}
	va_end(args);
	returnValue = counter - 1;
	return (returnValue);
}

int main(void)
{
	printf("%d\n", _printf("Hello %c_orld %s\n", 'W', "Jumanji"));

	return (0);
}
