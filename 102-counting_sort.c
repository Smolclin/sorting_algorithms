#include "sort.h"

/**
 * get_matrix - for getting maximum value of integers
 * @array: array of integers
 * @size: size of the array
 * Return: max integer in the array
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
 * counting_sort - sort an array of integers in ascending order
 * uing counting sort alogarithm
 * @array: the array of integers
 * @size: the size of the array
 * Description: prints the counting array after setting up
 */

void counting_sort(int *array, size_t size)
{
	int *count, *sortted, max, j;

	if (array == NULL || size < 2)
		return;

	sortted = malloc(sizeof(int) * size);
	if (sortted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sortted);
		return;
	}
	for (j = 0; j < (max + 1); j++)
		count[j] = 0;
	for (j = 0; j < (int)size; j++)
		count[array[j]] += 1;
	for (j = 0; j < (max + 1); j++)
		count[j] += count[j - 1];
	print_array(count, max + 1);

	for (j = 0; j < (int)size; j++)
	{
		sortted[count[array[j]] - 1] = array[j];
		count[array[j]] -= 1;
	}
	for (j = 0; j < (int)size; j++)
		array[j] = sortted[j];

	free(sortted);
	free(count);
}
