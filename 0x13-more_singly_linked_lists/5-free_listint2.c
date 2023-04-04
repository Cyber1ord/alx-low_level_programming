#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - function that frees a singly linked list
 * @head: double pointer to the head of the singly linked list
 * Return: nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *current, *next_node;

	if (head == NULL)
		return;

	current = *head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}

	*head = NULL;
}

