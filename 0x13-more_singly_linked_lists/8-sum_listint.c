#include "lists.h"

/**
 * sum_listint - function that returns the sum of all the data (n) of a
 * linked list.
 * @head: pointer to the head of a linked list
 * Return:  the sum of all the data (n).
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}

