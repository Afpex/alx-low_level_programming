#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all the elements of a linked list
 * @h: A pointer to the head of the listint_t list.
 *
 * Return: the number of nodes
 */

size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	for (; h != NULL; h = h->next, count++)
	{
		printf("%d\n", h->n);
	}

	return (count);
}
