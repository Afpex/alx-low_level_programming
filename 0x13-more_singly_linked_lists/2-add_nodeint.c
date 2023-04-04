#include "lists.h"

/**
 * add_nodeint - a function that adds a new node at the beginning of the list
 * @head: the pointer to the head of node
 * @n: number to be added to a node
 * Return: address of the new node that has been added
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (new_node != NULL)
	{
		new_node->n = n;
		new_node->next = *head;
	}
	else
		return (NULL);
	if (*head != NULL)
		new_node->next = *head;
	*head = new_node;
	return (new_node);
}
