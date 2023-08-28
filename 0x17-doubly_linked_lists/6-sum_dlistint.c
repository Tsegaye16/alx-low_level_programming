#include "lists.h"
/**
 * sum_dlistint - the method that returns the sum of all
 * the data (n) of a doubly linked list
 * @head: pointer to the head of the list
 * Return: sum or 0, if the list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current_node = head;
	int sum = 0;

	if (!head)
		return (sum);

	while (current_node)
	{
		sum += current_node->n;
		current_node = current_node->next;
	}

	return (sum);
}
