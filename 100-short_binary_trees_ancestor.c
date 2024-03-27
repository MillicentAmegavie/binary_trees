#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: If no common ancestors return NULL, else return common ancestor.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *m, *p;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	m = first->parent, p = second->parent;
	if (first == p || !m || (!m->parent && p))
		return (binary_trees_ancestor(first, p));
	else if (m == second || !p || (!p->parent && m))
		return (binary_trees_ancestor(m, second));
	return (binary_trees_ancestor(m, p));
}
