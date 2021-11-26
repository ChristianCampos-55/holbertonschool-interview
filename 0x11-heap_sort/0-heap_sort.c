#include "heap_sorter.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * heap_sort - Function that sorts an array in ascending order
 * @array: array to sort
 * @size: array's size
 * Return: zilch
 */

void heap_sort(int *array, size_t size)
{
	int i, holder;

	if (size < 2)
	{
		return;
	}

	for (i = size / 2 - 1; i >= 0; i--)
	{
		swapper(array, size, i, size);
	}

	for (i = size - 1; i >= 0; i--)
	{
		holder = array[0];
		array[0] = array[i];
		array[i] = holder;
		if (i != 0)
			print_array(array, size);
		swapper(array, i, 0, size);
	}
}

/**
 * swapper - Function to swap values
 * @array: array to swap
 * @size: array's size
 * @i: starter
 * @s: size int
 * Return: Zilch
 */

void swapper(int *array, int size, int i, int s)
{
	int bgest = i, holder;
	int a = 2 * i + 1;
	int b = 2 * i + 2;

	if (a < size && array[a] > array[bgest])
	{
		bgest = a;
	}

	if (b < size && array[b] > array[bgest])
	{
		bgest = b;
	}

	if (bgest != i)
	{
		holder = array[i];
		array[i] = array[bgest];
		array[bgest] = holder;
		print_array(array, s);
		swapper(array, size, bgest, s);
	}
}

