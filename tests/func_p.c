#include <stdio.h>

/**
*
*
*
*
*/

int add(int a, int b)
{
	return (a + b);
}

int main(void)
{
	int res;
	int (*fp)(int, int) = &add;

	res = fp(1,2);
	printf("%d\n", res);
	return (0);
}




