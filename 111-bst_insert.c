#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: value to store in the node to be inserted.
 * Return: pointer to the created node, or NULL on failure.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *c, *m;

	if (tree != NULL)
	{
		c = *tree;

		if (c == NULL)
		{
			m = binary_tree_node(c, value);
			if (m == NULL)
				return (NULL);
			return (*tree = m);
		}

		if (value < c->n) /* insert in left subtree */
		{
			if (c->left != NULL)
				return (bst_insert(&c->left, value));

			m = binary_tree_node(c, value);
			if (m == NULL)
				return (NULL);
			return (c->left = m);
		}
		if (value > c->n) /* insert in right subtree */
		{
			if (c->right != NULL)
				return (bst_insert(&c->right, value));

			m = binary_tree_node(c, value);
			if (m == NULL)
				return (NULL);
			return (c->right = m);
		}
	}
	return (NULL);
}
