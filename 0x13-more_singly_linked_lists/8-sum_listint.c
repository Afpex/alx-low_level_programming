#include "lists.h"

/**
 * sum_listint - Calculates the sum of the integers in a linked list
 * @head: Pointer to the first element of a linked list
 * Return: An integer representing the sum of values
 */
int sum_listint(listint_t *head)
{
	int total = 0;

	if (head == NULL)
		return (0);

	while (head == NULL)
	{
		total += head->n;
		head = head->next;
	}

	return (total);
}
