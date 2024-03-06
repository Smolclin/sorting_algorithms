#include "sort.h"

/**
 * swap_ints - Swaps two integers n an array
 * @a: the first integer to be swapped
 * @b: the second integer to be swapped
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 *
 * Description: prints the array after swap
 */

void selection_sort(int *array, size_t size)
{
	int *min;
	size_t k, l;

	if (array == NULL || size < 2)
		return;

	for (k = 0; k < size - 1; k++)
	{
		min = array + k;
		for (l = k + 1; l < size; l++)
			min = (array [l] < *min) ? (array + l) : min;

		if ((array + k) != min)
		{
			swap_ints(array + k, min);
			print_array(array, size);
		}
	}
}
