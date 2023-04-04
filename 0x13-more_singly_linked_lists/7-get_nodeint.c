#include "lists.h"
/**
 * get_nodeint_at_index - Returns the node at a specified index
 * @head: Pointer to the first element of the list
 * @index: Index of desired node
 * Return: Pointer to the desired node, or NULL if it doesn't exist
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; head && i < index; i++)
		head = head->next;

	return (head);
}
