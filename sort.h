#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

#define up 0
#define down 1

/**
 * enum bool - enumeration of boolen values
 * @false: equals 0
 * @true: equals 1
 */
typedef enum bool
{
	false = 0,
	true
}bool;

/**
 * struct listint_s - doubly linked list node
 * @n: node integer
 * @prev: pointer to previous elements in the list
 * @next: pointer to next element in the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
}listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

#endif
