#include "binary_trees.h"

/**
 * actual_checker - checks tree recursively
 * @tree: pointer to the root node of the tree to check
 * @m: minimun value
 * @ma: maximum value
 * @h: height of tree
 * Return: 1 if its AVL, otherwise 0
 */

int actual_checker(const binary_tree_t *tree, int m, int ma, int *h)
{
	int holder = 0, counter = 0;

	if (!tree)
		return (1);

	if (tree->n <= m || tree->n >= ma)
		return (0);

	if (!actual_checker(tree->left, m, tree->n, &holder) ||
		!actual_checker(tree->right, tree->n, ma, &counter))
		return (0);

	*h = MAX(holder, counter) + 1;
	return (ABS(holder - counter) <= 1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid
 * @tree: pointer to the root node of the tree to check
 * Return:  1 if tree is a valid AVL Tree, and 0 otherwise
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	int h;

	if (!tree)
		return (0);
	return (actual_checker(tree, INT_MIN, INT_MAX, &h));
}
