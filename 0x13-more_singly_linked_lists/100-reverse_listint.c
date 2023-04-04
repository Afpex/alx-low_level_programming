#include "lists.h"
/**
 * reverse_listint - Reverses a singly linked list
 * @head: pointer to the first element of the reversed list
 * Return: A pointer to the first element of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = *current;
		*current = next;
	}

	*head = prev;
	return (*head);
}
