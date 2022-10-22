#include <stdio.h> 
#include <stdlib.h>

/**
 * rtn_buffer- Function that returns buffer address
 *
 * Return: Buffer address
 */

char *rtn_buffer()
{

	char *buffer = malloc(sizeof(char) * 1024);
	snprintf(buffer, sizeof(buffer), "%s", "Baby");
	return (buffer);
}

int main(void)
{
	printf("Heap Address Allocated :%p\n", rtn_buffer());
	char *buffer = rtn_buffer();
	char *new_buffer = malloc(sizeof(char) * 1024);

	int len = 0; 
	while (buffer[len] != '\0')
	{
		putchar(buffer[len]);
		len++;
	}
	putchar('\n');
	printf("Length of string :%d\n", len);

	/* Appending the buffer */
	if (buffer[len] == '\0')
	{
		printf("End of String\n");
		new_buffer = &buffer[len];
		snprintf(new_buffer, sizeof(new_buffer), "%s\n", "Panda");
	}

	len = 0; 
	while (buffer[len] != '\0')
	{
		putchar(buffer[len]);
		len++;
	}
	printf("Length of appended string: %d\n", len);

	/* Writing to the buffer without using snprintf() */
	char str1[] = "Loves Bamboo";
	int i = 0;
	if (buffer[len] == '\0')
	{
		printf("End of appended Buffer\n");
		while(str1[i] != '\0')
		{
			buffer[len - 1] = str1[i];
			i++;
			len++;
		}
	}

	/* Printing Appended Buffer */
	len = 0; 
	while (buffer[len] != '\0')
	{
		/* printf("Writing to buffer\n"); */
		putchar(buffer[len]);
		len++;
	}
	putchar('\n');
	printf("Length of appended string: %d\n", len);
	return (0);
}
