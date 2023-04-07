#include "hash_tables.h"
/**
 * key_index - a function that gives you the index of a key
 * @key: The index of the key
 * @size: size of the array in the hash table
 * Return: the index of the key value pair
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

