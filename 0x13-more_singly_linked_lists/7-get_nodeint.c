#include "lists.h"

/**
 * get_nodeint_at_index - returns  node in random linked list at certain index
 * @head: goes to the first node in the linked list
 * @index: return to index of the node
 *
 * Return: pointer to the node we are looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}
