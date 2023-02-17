#include <stdio.h>

/**
 *  main - Entry point
 *  Description: Prints the alphabet in lowercase, and then in uppercase,
 *  followed by a new line using putchar function
 *  Return: Always 0 (Success)
 */

int main(void)
{
	char letter;
	/* print lowercase alphabet */
	for (letter = 'a'; letter <= 'z'; letter++)
		putchar(letter);
	/* print uppercase alphabet */
	for (letter = 'A'; letter <= 'Z'; letter++)
		putchar(letter);
	/* print new line */
	putchar('\n');
	return (0);
}
