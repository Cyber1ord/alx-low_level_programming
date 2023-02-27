#include "main.h"
#include <stdio.h>

/**
 * print_rev -  function that print a string
 * @s: string to be printed in reverse order
 * Return: length of string
 */
void print_rev(char *s)
{
	int i = 0;
	int len = 0;

	while (s[len] != '\0')
		len++;
	for (i = len - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
