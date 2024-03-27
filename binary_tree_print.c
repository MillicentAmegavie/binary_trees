#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * print_t - Stores recursively each level in an array of strings.
 * @tree: Pointer to print the node.
 * @offset: Offset to print.
 * @depth: node depth.
 * @s: Buffer.
 * Return: length of printed tree after process.
 */

static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char b[6];
	int w, l, r, i_l, m;

	if (!tree)
		return (0);
	i_l = (tree->parent && tree->parent->left == tree);
	w = sprintf(b, "(%03d)", tree->n);
	l = print_t(tree->left, offset, depth + 1, s);
	r = print_t(tree->right, offset + l + w, depth + 1, s);
	for (m = 0; m < w; m++)
		s[depth][offset + l + m] = b[m];
	if (depth && i_l)
	{
		for (m = 0; m < w + r; m++)
			s[depth - 1][offset + l + w / 2 + m] = '-';
		s[depth - 1][offset + l + w / 2] = '.';
	}
	else if (depth && !i_l)
	{
		for (m = 0; m < l + w; m++)
			s[depth - 1][offset - w / 2 + m] = '-';
		s[depth - 1][offset + l + w / 2] = '.';
	}
	return (l + w + r);
}

/**
 * _height - Measures the height of a binary tree.
 * @tree: Pointer to the node to measures the height.
 * Return: height of the tree starting at @node.
 */

static size_t _height(const binary_tree_t *tree)
{
	size_t h_l;
	size_t h_r;

	h_l = tree->left ? 1 + _height(tree->left) : 0;
	h_r = tree->right ? 1 + _height(tree->right) : 0;
	return (h_l > h_r ? h_l : h_r);
}

/**
 * binary_tree_print - Prints a binary tree.
 * @tree: Pointer to print the root node of the tree.
 */

void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t h, m, j;

	if (!tree)
		return;
	h = _height(tree);
	s = malloc(sizeof(*s) * (h + 1));
	if (!s)
		return;
	for (m = 0; m < h + 1; m++)
	{
		s[m] = malloc(sizeof(**s) * 255);
		if (!s[m])
			return;
		memset(s[m], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (m = 0; m < h + 1; m++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[m][j] != ' ')
				break;
			s[m][j] = '\0';
		}
		printf("%s\n", s[m]);
		free(s[m]);
	}
	free(s);
}
