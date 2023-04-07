#include "hash_tables.h"
/**
 * hash_table_create - a function that creates a hash table
 * @size: is the size of the
 * Return: If an error occurs - NULL
 *         otherwise - pointer to the new hash tabel
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i = 0;

	ht = malloc(sizeof(hash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->array = malloc(sizeof(hash_node_t *) *);
	if (ht->array == NULL)
		return (NULL);
	for (; i < size; i++)
		ht->array[i] = NULL;
	return (ht);
}
