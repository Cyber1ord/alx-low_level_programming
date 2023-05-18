#include "lists.h"

/**
 * dlistint_len - Counts the number of nodes in a linked list
 * @h: Pointer to the beginning of the linked list
 *
 * Return: Number of nodes in the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	if (h == NULL)
		return (0);
	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
