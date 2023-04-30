#include "lists.h"
/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint_end(listint_t **head, const int node)
{
	listint_t *new;
	listint_t *temporary = *head;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->node = node;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}

	while (temporary->next)
		temporary = temporary->next;

	temporary->next = new;

	return (new);
}
