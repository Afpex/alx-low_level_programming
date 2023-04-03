#include "lists.h"

/**
 * listint_len - counts the number of elements in a linked list
 * @h: head of the list
 *
 * Return: the number of nodes in the listint_t list.
 */

 size_t listint_len(const listint_t *h)
 {
 	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
