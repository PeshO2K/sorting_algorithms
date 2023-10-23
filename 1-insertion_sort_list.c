#include "sort.h"

/**
 * insertion_sort_list - bubble sort algorithm
 * @list: doubly linked list to be
 * sorted
 * Return: void
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *cursor;
	listint_t *current;
	listint_t *d_prev;

	if (list && *list && (*list)->next)
	{
		cursor = (*list)->next;
		for (; cursor ; cursor = cursor->next)
		{
			current = cursor;

			while (current->prev && (current->n < current->prev->n))
			{
				if (current->n < current->prev->n)
				{
					current->prev->next = current->next;
					if (current->next)
					{
						current->next->prev = current->prev;
					}
					d_prev = current->prev->prev;

					if (d_prev)
					{
						d_prev->next = current;
					}
					current->prev->prev = current;
					current->next = current->prev;
					current->prev = d_prev;
					if (!d_prev)
					{
						*list = current;
					}
					print_list(*list);
				}
			}
		}
	}
}
