#include "main.h"
#include <stdio.h>

/**
 * swap_int - function that takes a pointer to an int as
 * parameter and updates the value it points to to 98.
 * @a: First integer
 * @b: Second integer
 * Returns: Always 0
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
