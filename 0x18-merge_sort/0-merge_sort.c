#include "sort.h"

/**
 * actual_merge - merges two arrays
 * @size: array size
 * @array: array pointer
 * @left: l array pointer
 * @right: r array pointer
 **/
void actual_merge(size_t size, int *array, int *left, int *right)
{
	int a = 0, b = 0, c = 0;
	int l = size / 2;
	int r = size - l;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, l);
	printf("[right]: ");
	print_array(right, r);

	while (a < l && b < r)
		array[c++] = (left[a] < right[b]) ? left[a++] : right[b++];
	while (a < l)
		array[c++] = left[a++];
	while (b < r)
		array[c++] = right[b++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort -  function that sorts an array of integers in ascending order
 * @array: array pointer
 * @size:array size
 **/
void merge_sort(int *array, size_t size)
{
	size_t m, i;
	int l[2000], r[2000];

	if (!array || size < 2)
		return;
	for (i = 0, m = size / 2; i < m; i++)
		l[i] = array[i];
	for (i = m; i < size; i++)
		r[i - m] = array[i];

	merge_sort(l, m);
	merge_sort(r, size - m);
	actual_merge(size, array, l, r);
}
