#include "lists.h"
/**
 * reverse_listint - Reverses a singly linked list
 * @head: pointer to the first element of the reversed list
 * Return: A pointer to the first element of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return (NULL);

	listint_t *prev_node = NULL;
	listint_t *curr_node = *head;
	listint_t *next_node;

	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		curr_node->next = prev_node;
		prev_node = curr_node;
		curr_node = next_node;
	}
	*head = prev_node;
	return (*head);
}
