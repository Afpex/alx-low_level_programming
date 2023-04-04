#include "lists.h"

/**
 * free_linked_list - Frees a linked list of listint_t nodes
 * @head: Pointer to the first element of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *current_node, *next_node;

	if (head == NULL || *head == NULL)
		return;

	current_node = *head;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}

	*head = NULL;
}
