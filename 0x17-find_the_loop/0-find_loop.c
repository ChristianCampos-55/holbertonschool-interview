#include "lists.h"

/**
 * find_listint_loop - a function that finds the loop in a linked list
 * @head:	Pointer to list
 * Return:	address of the node where the loop starts
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *first_pointer, *sec_pointer;

	if (!head)
		return (NULL);

	sec_pointer = head->next;
	for (first_pointer = sec_pointer->next;
	sec_pointer && first_pointer && first_pointer->next;
	first_pointer = first_pointer->next->next)
	{
		if (sec_pointer == head || first_pointer == head)
			return (head);

		if (sec_pointer == first_pointer && first_pointer != head)
		{
			head = head->next;
			sec_pointer = head;
			first_pointer = head;
		}
		sec_pointer = sec_pointer->next;
	}
	return (NULL);
}