#include "lists.h"

/**
 * free_listint_safe - Frees a linked list safely (even if it has a loop)
 * @h: Double pointer to the head node of the list
 *
 * Return: The number of nodes in the list that were freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next;

	if (h == NULL || *h == NULL)
		return (count);

	current = *h;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		count++;

		if ((void *)next <= (void *)current)
		{
			*h = NULL;
			break;
		}

		current = next;
	}

	*h = NULL;
	return (count);
}

