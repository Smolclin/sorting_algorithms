#include "sort.h"

/**
 * get_max - gets the maximum in an array
 * @array: an array of integers
 * @size: the size of the array
 * Return: the max integer in the array
 */

int get_max(int *array, int size)
{
	int max, j;

	for (max = array[0], j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	return (max);
}

/**
 * radix_counting_sort -sorts the significant digits
 * @array: array of integers
 * @size: size of the array
 * @sig: the significant digit to sort
 * @buff: buffer to store the array
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t j;

	for (j = 0; j < 10; j++)
		count[(array[j] / sig) % 10] += 1;

	for (j = 0; j < 10; j++)
		count[j] += count[j - 1];

	for (j = size - 1; (int)j >= 0; j--)
	{
		buff[count[(array[j] / sig) % 10] - 1] = array[j];
		count[(array[j] / sig) % 10] -= 1;
	}

	for (j = 0; j < size; j++)
		array[j] = buff[j];
}

/**
 * radix_sort - sorts array of integers in ascending order
 * @array: array of integers
 * @size: the size of the array
 * Description: implements the LSD radixsort algorithm
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;
	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;
	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}
	free(buff);
}
