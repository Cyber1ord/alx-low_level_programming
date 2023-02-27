#include <stdio.h>
/**
 * printString - Function that print a string, follow by a new line
 * Return: Always 1
 * @str: string to print
 *
 */
void puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}
