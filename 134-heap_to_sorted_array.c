#include "binary_trees.h"

/**
 * tree_size - measures the sum of heights of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: Height or 0 if tree is NULL.
 */

size_t tree_size(const binary_tree_t *tree)
{
	size_t h_l = 0;
	size_t h_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		h_l = 1 + tree_size(tree->left);

	if (tree->right)
		h_r = 1 + tree_size(tree->right);

	return (h_l + h_r);
}

/**
 * heap_to_sorted_array - converts a Binary Max Heap to a sorted
 * array of integers.
 * @heap: pointer to the root node of the heap to convert.
 * @size: address to store the array size.
 * Return: pointer to array sorted in descending order.
 **/

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int m, *a = NULL;

	if (!heap || !size)
		return (NULL);

	*size = tree_size(heap) + 1;

	a = malloc(sizeof(int) * (*size));

	if (!a)
		return (NULL);

	for (m = 0; heap; m++)
		a[m] = heap_extract(&heap);

	return (a);
}
