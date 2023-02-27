#include "main.h"
#include <stdio.h>

/**
 * _puts -  function that print a string
 * @str: string to be printed
 * Return: length of string
 */
void _puts(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');

}

