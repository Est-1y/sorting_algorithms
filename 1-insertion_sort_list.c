#include "sort.h"

/**
 * swap_nodes - this swaps two nodes in a listint_t
 * doubly-linked list
 * @x: points to the head of the doubly-linked list
 * @n1: first node to swap
 * @n2: second node to swap
 */
void swap_nodes(listint_t **x, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*x = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - this sorts a doubly linked list of integers
 * @list: points to the head of a doubly-linked list of integers
 * Description: this prints the list after each swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
