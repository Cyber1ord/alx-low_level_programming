#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0
 *
 */
#include <stdio.h>
int main(void)
{
	unsigned long fib[50] = {1, 2};
	size_t i = 0;

	for (i = 2; i < 50; i++)
	{
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	i = 0;
	while (i < 50)
	{
		if (i < 49)
			printf("%lu, ", fib[i]);
		else
			printf("%lu\n", fib[i]);
		i++;
	}
	return (0);
}
