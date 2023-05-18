#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the beginning of the linked list
 * @idx: index at which to insert the new node
 * @n: data to enter into new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *current;
	unsigned int i;

	if (h == NULL)
		return (NULL);
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	new->next = NULL;
	if (idx == 0)
	{
		new->next = *h;
		if (*h != NULL)
			(*h)->prev = new;
		*h = new;
		return (new);
	}
	current = *h;
	for (i = 0; i < idx - 1; i++)
	{
		if (current == NULL)
		{
			free(new);
			return (NULL);
		}
		current = current->next;
	}
	if (current == NULL)
	{
		free(new);
		return (NULL);
	}
	new->next = current->next;
	new->prev = current;
	if (current->next != NULL)
		(current->next)->prev = new;
	current->next = new;
	return (new);
}
