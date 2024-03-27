#include "binary_trees.h"

/**
 * create_tree - creates an AVL tree with recursion.
 * @node: pointer node.
 * @array: input array of integers.
 * @size: array size.
 * @mode: 1 to adding on the left, 2 to adding on the right.
 * Return: .
 */

void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t m;

	if (size == 0)
		return;

	m = (size / 2);
	m = (size % 2 == 0) ? m - 1 : m;

	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[m]);
		create_tree(&((*node)->left), array, m, 1);
		create_tree(&((*node)->left), array + m + 1, (size - 1 - m), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[m]);
		create_tree(&((*node)->right), array, m, 1);
		create_tree(&((*node)->right), array + m + 1, (size - 1 - m), 2);
	}
}

/**
 * sorted_array_to_avl - creates root node and calls to create_tree.
 * @array: input array of integers.
 * @size: array size.
 * Return: pointer to the root.
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t m;

	root = NULL;

	if (size == 0)
		return (NULL);

	m = (size / 2);

	m = (size % 2 == 0) ? m - 1 : m;

	root = binary_tree_node(root, array[m]);

	create_tree(&root, array, m, 1);
	create_tree(&root, array + m + 1, (size - 1 - m), 2);

	return (root);
}
