#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapf(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integers in array
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
 * max_heap - turns a binary tree to binary heap
 * @array: an array of integers rep binary tree
 * @size: the size of the array tree
 * @base: the index of the base raw of the tree
 * @root: the root node of the binary tree
 */

void max_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;
	if (large != root)
	{
		swap_ints(array + root, array + large);
		max_heap(array, size, base, large);
	}
}

/**
 * heap_sort -sorts array of integers in ascending order
 * @array: array of integers
 * @size: the size of the array
 * Description: implements self-down heap sort alogarithm
 */

void heap_sort(int *array, size_t size)
{
	int j;

	if (array == NULL || size < 2)
		return;

	for (j = size - 1; j > 0; j--)
	{
		swap_ints(array, array + j);
		print_array(array, size);
		max_heap(array, size, j, 0);
	}
}
