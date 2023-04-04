#include "lists.h"
/**
 * delete_nodeint_at_index - Deletes a node at a designated index
 * @head: Pointer to the beginning of the list
 * @index: Index of the node to be freed
 * Return: 1 if successful, -1 if it fails
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int s;
	listint_t *current_node, *prev_node = NULL;

	if (head == NULL || *head == NULL)
		return (-1);

	current_node = *head;

	if (index == 0)
	{
		*head = current_node->next;
		free(current_node);
		return (1);
	}

	for (s = 0; current_node != NULL && s < index; s++)
	{
		prev_node = current_node;
		current_node = current_node->next;
	}

	if (current_node == NULL)
		return (-1);

	prev_node->next = current_node->next;
	free(current_node);

	return (1);
}
