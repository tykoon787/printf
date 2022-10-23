#include <stdlib.h>
#include <stdio.h> 

/* Works like a charm */

/**
 * rtn_buffer- Function that returns buffer address
 *
 * Return: Buffer address
 */

#define BUFFSIZE 1024

void *rtn_buffer()
{

	char *buffer = malloc(BUFFSIZE);
	snprintf(buffer, BUFFSIZE, "%s", "Baby Panda ");
	return (buffer);
}

void *append_buffer(char *buff_add, char *str)
{
	
	

	/* Check to See what the buffer contains. If it has anything, copy 
	* all their contenst to the main buffer */
	char *apd_buff = rtn_buffer();
	int len = 0;

	while (apd_buff[len] != '\0')
	{
		printf("Searching through buffer\n");
		len++;

	}
	printf("Reached End of Buffer. Start Appending\n");

	/* First append main buffer with buff_add */
	int i = 0;
	while (buff_add[i] != '\0')
	{
		printf("Appending Main Buffer with buffer_add\n");
		apd_buff[len] = buff_add[i];
		len++;
		i++;
	}

	/* Then append buffer with str */
	i = 0;
	while (str[i] != '\0')
	{
		apd_buff[len] = str[i];
		len++;
		i++;
	}
	buff_add = apd_buff;
	return(apd_buff);
}


int main(void)
{
	char str1[] = "Loves Babmoo";
	int *main_buffer = malloc(BUFFSIZE);
	char *buffer = append_buffer((char *)main_buffer, str1);
	printf("Heap Address Allocated :%p\n", buffer);

	/* Printing Appended Buffer */
	int i = 0;
	while (buffer[i] != '\0')
	{
		putchar(buffer[i]);
		i++;
	}

	putchar('\n');
	/* printf("Animals Like %s love the letter %c and the word %% %s %%\n",  */
	/* "Pandas", 'x', "Bamboo"); */
}
