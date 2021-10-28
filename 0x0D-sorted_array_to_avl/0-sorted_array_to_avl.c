#include "binary_trees.h"

/**
 * sorted_array_to_avl - create the tree
 * @array: to be converted
 * @size: of array
 * Return: h
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *h = NULL;

	if (array == NULL)
		return (NULL);
	if (bin(array, 0, (int)size - 1, &h) == NULL)
		return (NULL);
	return (h);
}

/**
 * bin - create tree
 * @array: to be converted
 * @p_start: start
 * @p_end: end
 * @h: space to be created
 * Return: h
 */

avl_t *bin(int *array, int p_start, int p_end, avl_t **h)
{
	int holder;
	avl_t *left = NULL, *right = NULL, *new_n = NULL;

	if (p_start > p_end)
		return (NULL);
	holder = (p_end + p_start) / 2;
	bin(array, p_start, holder - 1, &left);
	bin(array, holder + 1, p_end, &right);
	new_n = malloc(sizeof(avl_t));
	if (new_n == NULL)
		return (NULL);
	new_n->n = array[holder];
	new_n->parent = NULL;
	new_n->left = left;
	new_n->right = right;
	if (left != NULL)
		left->parent = new_n;
	if (right != NULL)
		right->parent = new_n;
	*h = new_n;
	return (new_n);
}
