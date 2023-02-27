#include <stdio.h>
#include "main.h"

/**
 * rev_string -  function that reverses a string
 * @s: string to be in reverse order
 * Return: length of string
 */
void rev_string(char *s)
{
	int i = 0;
	int len = 0;
	char tmp;

	while (s[len] != '\0')
		len++;

	for (i = len - 1; i >= len / 2; i--)
	{
		tmp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = tmp;
	}
}
