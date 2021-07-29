#include "lists.h"

/**
 * insert_node - insert new number linked list
 * @head: head to linked list
 * @number: numb to add to list
 * Return: list with new value or NULL
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *n_node = malloc(sizeof(listint_t));
	listint_t *pre = NULL;
	listint_t *crr_node = *head;

	if (!n_node)
	{
		return (NULL);
	}

	n_node->n = number;
	n_node->next = NULL;

	if (!*head)
	{
		*head = n_node;
	}

	else
	{
		while (crr_node && crr_node->n < number)
		{
			pre = crr_node;
			crr_node = crr_node->next;
		}
		if (!pre)
		{
			n_node->next = *head;
			*head = n_node;
		}
		else if (crr_node)
		{
			pre->next = n_node;
			n_node->next = crr_node;
		}
		else
		{
			pre->next = n_node;
		}
	}
	return (n_node);
}
