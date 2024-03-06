#include "sort.h"

/**
 * swap_ints - swap two integers in array
 * @a: the first integer to swap
 * @b: the second integer to swap
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * shell_sort - sort array of integers in ascending order
 * @array: array of integer
 * @size: the size of the array
 * Description: uses the knuth interval sequence
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, j, l;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;
	for (; gap >= 1; gap /= 3)
	{
		for (j = gap; j < size; j++)
		{
			l = j;
			while (l >= gap && array[l - gap] > array[l])
			{
				swap_ints(array + l, array + (l - gap));
				l -= gap;
			}
		}
		print_array(array, size);
	}
}
