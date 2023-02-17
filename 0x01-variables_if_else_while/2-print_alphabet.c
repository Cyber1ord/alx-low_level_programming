#include <stdio.h>
/**
 *  * main - Prints the lowercase alphabet followed by a new line
 *   *
 *    * Description: Prints the lowercase alphabet in ascending order,
 *     * followed by a new line, using only the putchar function twice.
 *      *
 *       * Return: Always 0 (Success)
 */

int main(void)
{
	char letter = 'a';

	while (letter <= 'z')
	{
		putchar(letter);
		letter++;
	}
	putchar('\n');
	return (0);
}

