#include "search.h"

/**
 * linear_skip - Looks for a value in a list
 * @list: Pointer to the head of said list
 * @value: Value to to be searched
 *
 * Return: Pointer to value searched or NULL upon failure
**/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skipper, *prev;
	skipper = list->f;
	prev = list;

    if (list == NULL)
		return (NULL);
	while (skipper)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   skipper->index, skipper->n);

		if (skipper->n >= value || !skipper->f)
		{

			if (!skipper->f && skipper->n < value)
			{
				prev = skipper;
				while (skipper->next)
					skipper = skipper->next;
			}

			printf("Value found between indexes [%lu] and [%lu]\n",
				   prev->index, skipper->index);

			while (prev)
			{
				printf("Value checked at index [%lu] = [%d]\n",
					   prev->index, prev->n);
				if (prev->n == value)
					return (prev);
				if (prev->n > value)
					return (NULL);
				prev = prev->next;
			}

			break;

		}
		prev = skipper;
		skipper = skipper->f;
	}
	return (NULL);
}
