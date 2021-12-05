#include "search_algos.h"

/**
* advanced_binary - Finds position of an item in sorted array
* @array: array vector
* @size: lenght of array
* @value: value to locate
* Return: index position of item or -1
*/

int advanced_binary(int *array, size_t size, int value)
{
	return (rec(array, array, size, value));
}

/**
* rec - finds position of an item in sorted array
* @array: array vector
* @copy: copy of array vector
* @size: lenght of array
* @value: value to locate
* Return: index position of item or -1
*/

int rec(int *array, int *copy, size_t size, int value)
{
	size_t a = 0;
	size_t splitter = (size - 1) / 2;

	if (size < 1)
		return (-1);

	printf("Searching in array: ");

	for (a = 0; a < size; a++)
	{
		if (a < size - 1)
			printf("%d%s", copy[a], ", ");
		else
			printf("%d%s", copy[a], "\n");
	}

	if (!splitter && *copy >= value)
	{
		if (*copy == value)
			return (copy - array);
		else
			return (-1);
	}

	if (copy[splitter] >= value)
		return (rec(array, copy, 1 + splitter, value));
	return (rec(array, copy + 1 + splitter, size - 1 - splitter, value));
}
