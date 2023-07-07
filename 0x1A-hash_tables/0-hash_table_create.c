#include "hash_tables.h"

/**
 * hash_table_create - Creates a hast table.
 * @size: The size of the array.
 *
 * Return: If an error occurs - NULL.
 * 	Otherwise - a pointer to the new hash table.
 */

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int b;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
	return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (b = 0; b < size; b++)
		ht->array[b] = NULL;

	return (ht);
}
