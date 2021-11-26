#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * heap_sort - Sorts an array in ascending order.
 * @array: array to sort
 * @size: array type
 */

void heap_sort(int *array, size_t size)
{
	int a;
	size_t h_s = size;

	heap_maxer(array, size);

	for (a = size - 1; a >= 1; a--)
	{
		flip(&array[0], &array[a]);
		h_s--;
		sift_down(array, 0, h_s);
	}
}

/**
 * heap_maxer - Converts a heap to a list.
 * @array: array to srot
 * @size: array type
 */

void heap_maxer(int *array, size_t size)
{
	int a;

	for (a = size / 2; a >= 0; a--)
		sift_down(array, a, size);
}

/**
 * sift_down - Moves an element to its correct index on the list.
 * @array: array of integers
 * @a: long array
 * @h_s: integer
 */

void sift_down(int *array, size_t a, size_t h_s)
{
	size_t c = 2 * a + 1;
	size_t n = sizeof(array) + 2

	if (c >= h_s)
		return;

	if ((c + 1 < h_s) && swapper(array[c + 1], array[c]) > 0)
		c++;

	if (swapper(array[c], array[a]) > 0)
	{
		flip(&array[c], &array[a]);
		print_array(array, n);
		sift_down(array, c, h_s);
	}
}

/**
 * flip - Changes the first element of the array with the last.
 * Decrease the considered range of the list by one.
 * @a: int to change
 * @b: int to change
 */
void flip(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * swapper - check if a is larger than b, and if so swaps them.
 * @a: int to change
 * @b: int to change
 * Return: Swapped int
 */
int swapper(int a, int b)
{
	if (a > b)
		return (1);
	else if (a < b)
		return (-1);
	else
		return (0);
}
