#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0 (Success)
 */
int main(void)
{
	int sum = 0, i = 1, j = 2, temp;

	while (j < 4000000)
	{
		if (j % 2 == 0)
		{
			sum += j;
		}
		temp = i;
		i = j;
		j = temp + j;
	}
	printf("%d\n", sum);
	return (0);
}
