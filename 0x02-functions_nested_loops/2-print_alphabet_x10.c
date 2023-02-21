#include <stdio.h>
#include "main.h"

/**
 * print_alphabet_x10 - function to print alphabet 10x
 *
 * Return: Always 0.
 *
 */
void print_alphabet_x10(void)
{
	char ch;
	int i = 0;

	while (i < 10)
	{
		ch = 'a';
		while (ch <= 'z')
		{
			_putchar(ch);
			ch++;
		}
		_putchar('\n');
		i++;
	}
}
