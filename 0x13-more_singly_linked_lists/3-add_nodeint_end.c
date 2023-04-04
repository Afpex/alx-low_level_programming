#include "lists.h"

/**
 * add_nodeint_end - Adds a new node to the end of a linked list.
 * @head: A pointer to a pointer to the first node of the list.
 * @n: The integer to be stored in the new node.
 *
 * Return: If the function fails - NULL.
 *         Otherwise - a pointer to the new node.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node, *tmp;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (*head == NULL)
	*head = new_node;

	else
	{
	tmp = *head;

	while (tmp->next != NULL)
	tmp = tmp->next;

	tmp->next = new_node;
	}

	return (new_node);
}
