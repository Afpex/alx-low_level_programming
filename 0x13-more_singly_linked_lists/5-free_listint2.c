#include "lists.h"

/**
 * my_free_listint2 - Frees a linked list and sets head to NULL
 * @head: Pointer to the first node in the list
 */
void my_free_listint2(listint_t **head)
{
	listint_t *current, *next;

	if (head == NULL)
		return;

	current = *head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*head = NULL;
}
