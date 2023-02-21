#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0
 *
 */
int main(void)
{
	int i;
	long int current = 1, prev = 1, temp;

	printf("%ld, %ld", current, prev);
	for (i = 2; i < 50; i++)
	{
		temp = current;
		current += prev;
		prev = temp;
		printf(", %ld", current);
	}
	printf("\n");
	return (0);
}
