#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: double pointer to the head node of a linked list
 * Return: the data of the deleted node or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	n = temp->n;
	*head = temp->next;
	free(temp);

	return (n);
}

