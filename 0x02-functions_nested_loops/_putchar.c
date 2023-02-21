#include <unistd.h>

/**
 * _purchar - writes the character c to stout
 * @c: the character to print
 *
 * Return: 0 (Success).
 *
 */
int _putchar(char c)
{
	return (write(1, & c, 1));
}
