#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a node at a given position.
 * @h: Pointer to a pointer to the first node on a linked list.
 * @idx: Position for node to be inserted.
 * @n: Number in the node.
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp;
	dlistint_t *new_node;
	unsigned int counter = 0;

	if (h == NULL)
		return (NULL);

	new_node = create_node(n);
	if (new_node == NULL)
		return (NULL);

	if (idx == 0)
	{
		new_node->next = *h;
		if (*h != NULL)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	tmp = *h;
	while (tmp != NULL)
	{
		if (counter + 1 == idx)
		{
			new_node->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = new_node;
			tmp->next = new_node;
			new_node->prev = tmp;
			return (new_node);
		}
		tmp = tmp->next;
		counter++;
	}

	free(new_node);
	return (NULL);
}
