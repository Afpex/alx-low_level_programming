#include "lists.h"

/**
 * add_nodeint_t - function that addsa new node at the end of the listint_t
 * @head: Pointer to the beginning of a list
 * @n: the datatype added to the node
 * Return: A pointer to the beginning of the listint_t
 */

listint_t *add_nodeint_end(listint_t **head, const int n);
{
	listint_t *new_node;
	listint_t *temp_node = *head

	new_node = malloc(sizeof(listint_t));
	if (new_node != NULL)
	{
		new_mode->n = n;
		new_node->next = NULL;
	}
	else
		return (NULL);
	if (*head == NULL)
		*head = new_node;
	else
	{
		listint_t *current = *head;

	while (current->next != NULL)
		{
		current = current->next;
		}
	current->next = new_node;
	}

	return (new_node);
}
