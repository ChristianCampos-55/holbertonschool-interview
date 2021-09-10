#include "lists.h"

/**
 * check_cycle - Checks if linked list has a cycle or not
 * @list: Head of the linked list
 *
 * Return: 0 if no cycle, 1 otherwise
 */

int check_cycle(listint_t *list)
{
	listint_t *c_one, *c_two;

	if (!list)
		return (0);

	c_one = list;
	c_two = list;

	while ((c_one) && (c_two) && (c_two->next))
	{
		c_one = c_one->next;
		c_two = c_two->next->next;

		if (c_one == c_two)
			return (1);
	}
	return (0);
}
