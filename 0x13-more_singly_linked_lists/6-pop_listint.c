#include "lists.h"

/**
 * pop_listint - Deletes the first node of a list
 * @head: pointer to the first node of the list
 * Return: The integer value inside the deleted node
 */
int pop_listint(listint_t **head)
{
	int num;
	listint_t *temp;

	if (head == NULL || *head == NULL)
	return (0);
	num = (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);
	return (num);
}
