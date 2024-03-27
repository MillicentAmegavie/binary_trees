#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: pointer to the parent of the node to create.
 * @value: value to put in the new node.
 * Return: If an error occurs - NULL.
 * Otherwise - a pointer to the new node.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *m;

	m = malloc(sizeof(binary_tree_t));
	if (m == NULL)
		return (NULL);

	m->n = value;
	m->parent = parent;
	m->left = NULL;
	m->right = NULL;

	return (m);
}
