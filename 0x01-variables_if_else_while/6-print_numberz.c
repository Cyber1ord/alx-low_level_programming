#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints all single digit numbers of base 10 starting from 0,
 * followed by a new line, using only the putchar function.
 *
 * Return: Always 0 (Success)
 *
 */
int main(void)
{
	int num = 48; /* ASCII code for '0' */

	while (num <= 57) /* ASCII code for '9' */
	{
		putchar(num);
		num++;
	}
	putchar('\n');
	return (0);
}
