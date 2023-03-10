#include "main.h"
#include <stdio.h>

/**
 * _strlen -  function that returns the length of a string
 * @s: length of string
 * Return: length of string
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}
