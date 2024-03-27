#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as a left-child of
 * another in a binary tree.
 * @parent: pointer to the node to insert the left-child in.
 * @value: value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 * Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a left-child, the new node
 * takes its place and the old left-child is set as the left-child
 * of the new node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *m;

	if (parent == NULL)
		return (NULL);

	m = binary_tree_node(parent, value);
	if (m == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		m->left = parent->left;
		parent->left->parent = m;
	}
	parent->left = m;

	return (m);
}
