#include "lists.h"

/**
 * free_listint_nodes - Frees a linked list
 * @head: Pointer to the first node in the list
 */
void free_listint(listint_t *head)
{
	listint_t *current_node, *next_node;

	if (head == NULL)
		return;

	current_node = head;

	while (current_node->next != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	free(current_node);
}
