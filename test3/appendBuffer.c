#include <stdlib.h>
#include <stdio.h> 

/* Works like a charm */

/**
 * rtn_buffer- Function that returns buffer address
 *
 * Return: Buffer address
 */

extern char *main_buffer_address;

char *rtn_buffer()
{

	char *main_buffer_address = malloc(sizeof(char) * 1024);
	snprintf(main_buffer_address, sizeof(main_buffer_address), "%s", "Baby");
	return (main_buffer_address);
}

char *append_buffer(char *buff_add, char *str)
{
	char *appended_buffer;
	buff_add = main_buffer_address;

	int len = 0;
	while (buff_add[len] != '\0')
	{
		printf("Searching through buffer\n");
		len++;

	}
	printf("Reached End of Buffer. Start Appending\n");

	int i = 0;
	while (str[i] != '\0')
	{
		buff_add[len] = str[i];
		len++;
		i++;
	}
	appended_buffer = main_buffer_address;
	return(appended_buffer);
}


int main(void)
{
	char *buffer = main_buffer_address;
	printf("Heap Address Allocated :%p\n", buffer);
	char *new_buffer = malloc(sizeof(char) * 1024);

	/* Appending Buffer using append_buffer()*/
	char str1[] = "Loves Babmoo";

	char *appended_buffer = append_buffer(buffer, str1);

	/* Printing Appended Buffer */
	int i = 0;
	while (appended_buffer[i] != '\0')
	{
		putchar(appended_buffer[i]);
		i++;
	}
}
