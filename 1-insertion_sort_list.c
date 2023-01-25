#include "sort.h"

/**
 * swap - swap 2 nodes
 * @node_right: first node
 * @node_left: second node
 * Return: swaped node
 */

listint_t *swap(listint_t *node_right, listint_t *node_left)
{
	listint_t *temp1, *temp2;

	temp1 = node_right->prev;
	temp2 = node_left->next;

	node_left->next = node_right;
	node_right->prev = node_left;
	node_left->prev = temp1;
	node_right->next = temp2;

	if (temp1)
		temp1->next = node_left;
	if (temp2)
		temp2->prev = node_right;
	return (node_left);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: the list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list;

	while (node && node->next)
	{
		if (node->n > node->next->n)
		{
			node = swap(node, node->next);
			if (node->prev == NULL)
				*list = node;
			print_list(*list);

			while (node && node->prev && node->n < node->prev->n)
			{
				node = swap(node->prev, node);
				if (node->prev == NULL)
					*list = node;
				print_list(*list);
			}
		}
		node = node->next;
	}
}
