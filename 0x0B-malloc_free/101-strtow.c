#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * count_words - counts the number of words in a string
 * @str: the input string
 *
 * Return: the number of words
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			count++;
		}
	}

	return (count);
}

/**
 * strtow - splits a string into words
 * @str: the input string
 *
 * Return: a pointer to an array of strings, or NULL if str is NULL or empty
 */
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
		return (NULL);

	int i, j, k, len, words;
	char **result;

	words = count_words(str);
	result = malloc(sizeof(char *) * (words + 1));
	if (result == NULL)
		return (NULL);

	for (i = 0, j = 0; i < words; i++)
	{
		while (str[j] == ' ')
			j++;

		len = 0;
		while (str[j + len] != ' ' && str[j + len] != '\0')
			len++;

		result[i] = malloc(sizeof(char) * (len + 1));
		if (result[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(result[k]);
			free(result);
			return (NULL);
		}

		memcpy(result[i], &str[j], len);
		result[i][len] = '\0';

		j += len;
	}

	result[words] = NULL;

	return (result);
}
