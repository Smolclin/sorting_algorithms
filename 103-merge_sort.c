#include "sort.h"

void marge_subar(int *subar, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subar, int *buff, size_t front, size_t back);

/**
 * merge_subar - sort integer subarray
 * @subar: subarray to sort
 * @buff: buffer for storing sorted subarray
 * @front: front of the array
 * @mid: mid of the array
 * @back: back of the array
 */

void merge_subar(int *subar, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t j, k, l = 0;

	printf("Merging...\n[left]: ");
	print_array(subar + front, mid - front);

	printf("[right]: ");
	print_array(subar + mid, back - mid);

	for (j = front, k = mid; j < mid && k < back; l++)
		buff[l] = (subar[j] < subar[k] ? subar[j++] : subar[k++]);
	for (; j < mid; j++)
		buff[l++] = subar[j];
	for (; k < back; k++)
		buff[l++] = subar[k];
	for (j = front, l = 0; j < back; j++)
		subar[j] = buff[l++];

	printf("[Done]: ");
	print_array(subar + front, back - front);
}

/**
 * merge_sort_recursive - implements merging and sorting through recursion
 * @subar: a subarray of the array
 * @buff: a buff to store sorted results
 * @front: the front of the subarray
 * @back: the back of the subarra
 */

void merge_sort_recursive(int *subar, int *buff, size_t front, size_t back)
{
	size_t id;

	if (back - front > 1)
	{
		id = front + (back - front) / 2;
		merge_sort_recursive(subar, buff, front, id);
		merge_sort_recursive(subar, buff, id, back);
		merge_subar(subar, buff, front, id, back);
	}
}
/**
 * merge_sort - sort an array of integers in ascending order
 * @array: array of integers
 * @size: size of the array
 * Description: implements the top-down merge sort
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
