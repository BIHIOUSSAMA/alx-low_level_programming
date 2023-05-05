#include "lists.h"

/**
 * print_listint - prints all elements of linked list
 * @h: linked list of a type listint_t to print
 *
 * Return:the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t num = 0;

	while (w)
	{
		printf("%d\n", w->n);
		num++;
		w = w->next;
	}

	return (num);
}

