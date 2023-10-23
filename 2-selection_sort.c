#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: doubly linked list to be sorted
 * @size: size of array
 * Return: void
*/

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min_idx;
	int temp;

	for (; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1 ; j < size ; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
