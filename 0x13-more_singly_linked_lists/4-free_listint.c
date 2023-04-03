#include "lists.h"
#include <stddef.h>

/**
 * free_listint - frees a linked list of type listint_t
 * @head: pointer to the head of the linked list
 *
 * Return: void
 */
void free_listint(listint_t *head)

{
	if (head != NULL)
	{
		if (head->next != NULL)
			free_listint(head->next);
		free(head);
	}
}
