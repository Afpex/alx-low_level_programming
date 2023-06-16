#include "lists.h"

/**
 * dlistint_len - prints all the elements of a dlistint_t list
 * @h: head of the list
 *
 * Return: the number of nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 1;
	const dlistint_t *current = h;

	if (h == NULL)
		return (0);

	while (current->next != NULL)
	{
		current = current->next;
		count++;
	}

	return (count);
}
