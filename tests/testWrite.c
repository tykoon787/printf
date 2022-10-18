#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main- Entry Point
 *
 * Return: Always (0)
 */

int main(void)
{
	char *buff;
	int i;
	char *string;

	buff = malloc(sizeof(char) * 11);

	char str1[12] = "Baby Panda";

	for (i = 0; i < 10; i++)
	{
		buff[i] = str1[i];
	}
	buff[i] = '\0';

	write(1, buff, strlen(str1));
	putchar('\n');
	printf("%s\n", str1); /* writes to stdout --> fd 1. */
	return (0);
}
