#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFSIZE 1024

int _printf(const char *format, ...);
void *rtn_buffer();
void *append_buffer(char *buff_add);
int _putchar(char c);
void *print_perc(__attribute__((unused))va_list arg_perc);
void *print_char(va_list arg_c);
void *print_str(va_list arg_str);

#endif /* MAIN_H */
