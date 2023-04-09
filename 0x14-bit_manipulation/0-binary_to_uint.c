#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned integer
 *
 * @b: A pointer to a string of 0 and 1 characters
 *
 * Return: The converted number, or 0 if there is an invalid character in the
 *         string or b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b != '0' && *b != '1')
			return (0);

		if (*b == '1')
		{
			num = (num << 1) | 1;
		}
		else
		{
			num <<= 1;
		}

		b++;
	}

	return (num);
}

