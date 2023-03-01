#include "main.h"
#include <stdio.h>
#include "holberton.h"

/**
 * _strcmp - Compare two strings.
 * @s1: First string to be compared.
 * @s2: Second string to be compared.
 *
 * Return: An integer greater than, equal to, or less than 0, according to
 * whether the string s1 is greater than, equal to, or less than the string s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			break;
	}
	return (s1[i] - s2[i]);
}
