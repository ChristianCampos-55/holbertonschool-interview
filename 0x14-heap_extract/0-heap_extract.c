#include "binary_trees.h"

/**
 * calc_height - returns the height of a tree
 * @tree: pointer to binary tree
 * Return: The height of the tree starting from the head
 */

size_t calc_height(const binary_tree_t *tree)
{
	size_t h_l, h_r;
	size_t h = 0;

	if (tree->left)
		h_l = 1 + calc_height(tree->left);
	else
		h_l = 0;
	if (tree->right)
		h_r = 1 + calc_height(tree->right);
	else
		h_r = 0;
	if (h_l > h_r)
		h = h_l;
	else
		h = h_r;
	return (h);
}

/**
 * rec_transiter - goes through a binary tree
 * @root: root of the tree
 * @node: actual node in tree
 * @h: tree height
 * @f: actual node
 **/

void rec_transiter(heap_t *root, heap_t **node, size_t h, size_t f)
{
	if (!root)
		return;
	if (h == f)
		*node = root;
	f++;

	if (root->left)
		rec_transiter(root->left, node, h, f);
	if (root->right)
		rec_transiter(root->right, node, h, f);
}

/**
 * sorter -	sorts the binary tree
 * @node: actual node in tree
 * Return: sorted tree
 **/

heap_t *sorter(heap_t *node)
{
	int holder;

	while (node->left || node->right)
	{
		if (!node->right || node->left->n > node->right->n)
		{
			holder = node->n;
			node->n = node->left->n;
			node->left->n = holder;
			node = node->left;
		}
		else if (!node->left || node->left->n < node->right->n)
		{
			holder = node->n;
			node->n = node->right->n;
			node->right->n = holder;
			node = node->right;
		}
	}
	return (node);
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: root of the tree
 * Return: value stored in the root node
 **/

int heap_extract(heap_t **root)
{
	int value, h, f;
	heap_t *temp, *node;

	f = 0;
	if (!root || !*root)
		return (f);

	temp = *root;
	value = temp->n;
	if (!temp->right && !temp->left)
	{
		*root = NULL;
		free(temp);
		return (value);
	}
	f = 0;
	h = calc_height(temp);
	rec_transiter(temp, &node, h, f);
	temp = sorter(temp);
	temp->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (value);
}
