#include "main.h"

/**
 * get_bit - Returns the value of the bit at a given index in a number.
 * @n: The number to check the bit in.
 * @index: The index of the bit to get, starting from 0.
 *
 * Return: The value of the bit at index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned int i;

	if (index >= 64)
	{
		return (-1);
	}
	i = ((n >> index) & 1);
	return (i);
}

