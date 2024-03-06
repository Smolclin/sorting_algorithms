#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * @a: the first integer
 * @b: the second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sorts the array of integers in ascending oreder
 * @array: array of integers to sort
 * @size: size of the array
 *
 * Description: print the array after each swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t  i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;
	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
