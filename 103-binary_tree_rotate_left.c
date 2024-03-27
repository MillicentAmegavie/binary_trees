#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 * Return: pointer to the new root node after rotation.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *p, *t;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	p = tree->right;
	t = p->left;
	p->left = tree;
	tree->right = t;
	if (t != NULL)
		t->parent = tree;
	t = tree->parent;
	tree->parent = p;
	p->parent = t;
	if (t != NULL)
	{
		if (t->left == tree)
			t->left = p;
		else
			t->right = p;
	}

	return (p);
}
