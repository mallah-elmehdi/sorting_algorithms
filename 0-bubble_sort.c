#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 *
 * @array: the array to be sorted
 * @size: the array's size
 */
void bubble_sort(int *array, size_t size)
{
	int swap;
	size_t i;
	size_t j;
	size_t n;

	n = size;
	while (size)
	{
		i = 0;
		j = 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
				print_array(array, n);
			}
			j++;
			i++;
		}
		size--;
	}
}
