#include "main.h"

/**
 * flip_bits - returns the number of bits you would
 * need to flip to get from one number to another
 * @n: number one.
 * @m: number two.
 *
 * Return: number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int flip_no, i;

	flip_no = n ^ m;
	i = 0;

	while (flip_no)
	{
		if (flip_no & 1)
			i++;
		flip_no >>= 1;
	}

	return (i);
}
