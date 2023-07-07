#include "hash_tables.h"
/**
 * hash_table_delete - The method(function) that removes a hash table
 *
 * @ht: Hash table
 **/
void hash_table_delete(hash_table_t *ht)
{
	unsigned int index;
	hash_node_t *tmp, *aux;

	if (!ht || !ht->array)
		return;

	for (index = 0; index < ht->size; index++)
	{
		tmp = ht->array[index];
		while (tmp != NULL)
		{
			aux = tmp->next;
			free(tmp->value);
			free(tmp->key);
			free(tmp);

			tmp = aux;
		}
	}
	free(ht->array);
	free(ht);
}
