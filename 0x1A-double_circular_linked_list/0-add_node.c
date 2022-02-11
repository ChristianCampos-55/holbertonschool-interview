#include "list.h"

/**
 * add_node_begin - Add a new node to a double circular linked list
 * @list: the list to modify 
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_begin(List **list, char *str)
{
	List *n = NULL;

	n = add_node_end(list, str);
	if (!n)
	{
		return (NULL);
	}

	*list = n;
	return (n);
}

/**
 * add_node_end - Add a new node to a double circular linked list
 * @list: the list to modify 
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_end(List **list, char *str)
{
	List *n = NULL;

	if (!list)
		return (NULL);
	n = malloc(sizeof(List));
	if (!n)
		return (NULL);
	n->str = strdup(str);
	if (!(n->str))
		return (NULL);
	if (!*list)
	{
		n->next = n;
		n->prev = n;
		*list = n;
	}
	else
	{
		n->next = *list;
		n->prev = (*list)->prev;
		(n->next)->prev = n;
		(n->prev)->next = n;
	}
	return (n);
}
