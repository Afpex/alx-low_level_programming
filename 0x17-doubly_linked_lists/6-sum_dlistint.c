#include "lists.h"

/**
 * sum_dlistint - Calculates the sum of all data of a linked list.
 * @head: Pointer to the first node on a linked list.
 * Return: The sum of all elements in the linked list. Or 0 if the linked list
 * is empty.
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
