#include "lists.h"

/**
 * pop_listint - deletes the head node of a singly linked list and
 * returns its data
 * @head: pointer to the pointer to the head node of the list
 * Return: data of the head node, or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	int data;
	listint_t *temp;

	if (*head == NULL) {
		return 0;
	}

	temp = *head;
	data = temp->n;
	*head = (*head)->next;
	free(temp);

	return data;
}
