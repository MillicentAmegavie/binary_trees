#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 * Return: A pointer to the root node of the created AVL, or NULL upon failure.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
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
			if (avl_insert(&tree, array[m]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
