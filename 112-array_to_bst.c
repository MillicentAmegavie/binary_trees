#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size: number of elements in @array.
 * Return: pointer to the root node of the created BST, or NULL upon failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t m, k;

	if (array == NULL)
		return (NULL);

	for (m = 0; m < size; m++)
	{
		for (k = 0; k < m; k++)
		{
			if (array[k] == array[m])
				break;
		}
		if (k == m)
		{
			if (bst_insert(&tree, array[m]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
