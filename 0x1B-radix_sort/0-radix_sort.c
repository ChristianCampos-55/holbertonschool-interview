#include "sort.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * counter - count sort
 * @array: contain only numbers to be sorted
 * @size: array size
 * @temp: temporary array
 * @current: current expo
 * Return: Changed array
 */

int counter(int *array, ssize_t size, int *temp, long current)
{
	ssize_t i;
	int count[10] = {0}, ret = 0;

	for (i = 0; i < size; i++)
		count[(array[i] / current) % 10]++, temp[i] = 0;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
		temp[--count[(array[i] / current) % 10]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	return (ret);
}

/**
 * radix_sort - radix sort algorithm
 * @array: contain only numbers to be sorted
 * @size: array size
 */

void radix_sort(int *array, size_t size)
{
	int top = INT_MIN, *temp = NULL;
	size_t i = 0;
	long current;

	if (!array || size < 2)
		return;
	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		return;
	for (i = 0; i < size; i++)
		top = array[i] > top ? array[i] : top;
	for (current = 1; top / current > 0; current *= 10)
	{
		counter(array, size, temp, current);
		print_array(array, size);
	}
	free(temp);
}
