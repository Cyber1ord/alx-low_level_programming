#include "lists.h"
#include <stdio.h>

/**
 * listint_len - function that returns the number of elements in a
 * linked list
 * @h: list to count elements
 * Return: number or the elements of the list
 */
size_t listint_len(const listint_t *h)
{
	size_t c = 0;

	while (h != NULL)
	{
		h = h->next;
		c++;
	}

	return (c);
}
