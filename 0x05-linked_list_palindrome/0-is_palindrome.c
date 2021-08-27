#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* list_checker - checks nodes recursively
* @l_node: checks left nodes of list
* @r_node: checks right nodes of list
* Return: 1 if its a palindrome, 0 otherwise
*/
int list_checker(listint_t **l_node, listint_t *r_node)
{
	int res;

	if (r_node == NULL)
	{
		return (1);
	}
	res = list_checker(l_node, r_node->next) && (*l_node)->n == r_node->n;
	*l_node = (*l_node)->next;
	return (res);
}


/**
* is_palindrome - Checks wether the passed list is a palindrome or not
* @head: head of list
* Return: 1 if its a palindrome, 0 otherwise
*/
int is_palindrome(listint_t **head)
{
	listint_t *ref = *head;

	return (list_checker(&ref, ref));
}
