#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort algorithm
 *
 * @array: the array to be sorted
 * @size: the array's size
 */

void selection_sort(int *array, size_t size)
{
	int swap;
	size_t current;
	size_t min;
	size_t i;

	i = 0;
	while (i < size)
	{
		current = i;
		min = i;
		while (current < size)
		{
			if (array[min] > array[current])
				min = current;
			current++;
		}
		swap = array[i];
		array[i] = array[min];
		array[min] = swap;
		print_array(array, size);
		i++;
	}
}
