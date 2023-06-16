#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a dlistint_t list.
 * @h: Pointer to the head node of a linked list.
 * Return: The number of nodes on the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t s;

	if (h == NULL)
		return (0);
	for (i = 0; h != NULL; i++)
		h = h->next;
	return (s);
}
