#include "sort.h"

/*
 * swap_nodes -  swaps two nodes in doubly linked lidt
 * @h: pointer to the head of a doubly linked list
 * @n1: pointer to the first node
 * @n2: pointer to the next noode
 */

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	else
		*h = n2;
	(*n1)->prev = n2;
}

/**
 * insertion_sort_list - sorts doubly linked list
 * by use of insertiuon sort algorithm
 * @list: pointer to head of doubly linked list
 * Description: prints the list of each swap
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *item, *inset, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (item = (*list)->next; item != NULL; item = tmp)
	{
		tmp = item->next;
		inset = item->prev;
		while (inset != NULL && item->n < inset->n)
		{
			swap_nodes(list, &inset, item);
			print_list((const listint_t *)*list);
		}
	}
}
