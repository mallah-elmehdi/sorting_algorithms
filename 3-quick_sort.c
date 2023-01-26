#include "sort.h"

/**
 * get_pivot_lomuto - get the pivot Lomuto partition scheme
 *
 * @arr: the array to be sorted
 * @low: low
 * @high: high
 * @size: the array's size
 */
int get_pivot_lomuto(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1);
	int swap;
	int j = low;

	for (; j <= high - 1; j++)
	{
		if (arr[high] <= pivot)
		{
			i++;
			swap = arr[i];
			arr[i] = arr[high];
			arr[high] = swap;
			print_array(arr, size);
		}
	}
	swap = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = swap;
	return (i + 1);
}

/**
 * my_quick_sort - quick sort
 *
 * @arr: the array to be sorted
 * @low: low
 * @high: high
 * @size: the array's size
 */
void my_quick_sort(int *arr, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = get_pivot_lomuto(arr, low, high, size);

		my_quick_sort(arr, low, pi - 1, size);
		my_quick_sort(arr, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 *
 * @array: the array to be sorted
 * @size: the array's size
 */
void quick_sort(int *array, size_t size)
{
	my_quick_sort(array, 0, size - 1, size);
}
