#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	unsigned long int j = 1, k = 2, temp, sum = 0;

	for (i = 1; i <= 33; i++)
	{
		if (j != 4000000 && (j % 2 == 0))
			sum += j;
		temp = j + k;
		j = k;
		k = temp;
	}
	printf("%lu\n", sum);
	return (0);
}
