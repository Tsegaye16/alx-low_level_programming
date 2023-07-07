#include "hash_tables.h"
/**
 * hash_table_print - The method(function) that displays hashtable
 * @ht: the hash table you want to print
 */
void hash_table_print(const hash_table_t *ht)
{

unsigned long int n;
hash_node_t *node;
short int comma = 0;

if (ht == NULL)
	return;

putchar('{');
for (n = 0; n < ht->size; n++)
{
	node = ht->array[n];
	while (node != NULL)
	{
		if (comma)
			printf(", ");

		printf("'%s': '%s'", node->key, node->value);
		node = node->next;

		if (comma == 0)
			comma = 1;
	}
}
printf("}\n");
}
