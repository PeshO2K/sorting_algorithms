#include "sort.h"

/**
 * quick_sort - quick sort algorithm
 * @array: doubly linked list to be
 * sorted
 * @size: size of array
 * Return: void
*/


void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

size_t partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i = low, j = low;
	int piv_value = array[high];


	for (; j < high; j++)
	{
		if (array[j] <= piv_value)
		{
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
			{
				print_array(array, size);
			}

			i++;
		}
	}
	swap(&array[i], &array[high]);
	if (array[i] != array[high])
	{
		print_array(array, size);
	}

	return (i);
}
void quick_sort_recurs(int *array, size_t low, size_t high, size_t size)
{
	size_t piv_idx;

	if (low < high)
	{
		piv_idx = partition(array, low, high, size);
		if (piv_idx != 0)
		{
			quick_sort_recurs(array, low, piv_idx - 1, size);
		}
		if (piv_idx < size - 1)
		{
			quick_sort_recurs(array, piv_idx + 1, high, size);
		}


	}
}
void quick_sort(int *array, size_t size)
{
	quick_sort_recurs(array, 0, size - 1, size);
}
