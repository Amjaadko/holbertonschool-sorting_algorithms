#include "sort.h"

/**
 * swap - swaps two elements in an array
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int tmp;

	if (a == b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index (pivot)
 * @size: size of the array (for printing)
 * Return: index of pivot after partition
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int pivot = array[high];

	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_rec - recursive function to sort array
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array (for printing)
 */
void quick_sort_rec(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		if (pivot_index > 0)
			quick_sort_rec(array, low, pivot_index - 1, size);
		quick_sort_rec(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm
 * @array: array to sort
 * @size: number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}

