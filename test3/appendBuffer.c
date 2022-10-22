#include <stdlib.h>
#include <stdio.h> 

/* Works like a charm */

/**
 * rtn_buffer- Function that returns buffer address
 *
 * Return: Buffer address
 */

#define BUFFSIZE 1024

char *rtn_buffer()
{

	char *buffer = malloc(sizeof(char) * 1024);
	snprintf(buffer, BUFFSIZE, "%s", "Baby Panda ");
	return (buffer);
}

char *append_buffer(char *str)
{
	char *buff_add = rtn_buffer();

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
	return(buff_add);
}


int main(void)
{
	char str1[] = "Loves Babmoo";
	char *buffer = append_buffer(str1);
	printf("Heap Address Allocated :%p\n", buffer);

	/* Printing Appended Buffer */
	int i = 0;
	while (buffer[i] != '\0')
	{
		putchar(buffer[i]);
		i++;
	}
}
