#include <stdio.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the head of a linked list
 * @idx: index of nodes in the linked list
 * @n: number to insert
 *
 * Return: the address of the new node or NULL if failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current = *head;
	listint_t *new_node = malloc(sizeof(listint_t));
	unsigned int i = 0;

	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	if (i == idx - 1 && current != NULL)
	{
		new_node->next = current->next;
		current->next = new_node;
		return (new_node);
	}

	free(new_node);
	return (NULL);
}

