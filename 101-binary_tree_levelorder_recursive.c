#include "binary_trees.h"

/**
 * struct node_s - singly linked list.
 * @node: const binary tree node.
 * @next: points to the next node.
 */

typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} ll;

ll *append(ll *head, const binary_tree_t *btnode);
void free_list(ll *head);
ll *get_children(ll *head, const binary_tree_t *parent);
void levels_rec(ll *head, void (*func)(int));

/**
 * binary_tree_levelorder - Goes through a binary tree
 * using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	ll *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * levels_rec - Calls func on all nodes at each level.
 * @head: Pointer to head of linked list with nodes at one level.
 * @func: Pointer to a function to call for each node.
 */

void levels_rec(ll *head, void (*func)(int))
{
	ll *children = NULL, *c = NULL;

	if (!head)
		return;
	for (c = head; c != NULL; c = c->next)
	{
		func(c->node->n);
		children = get_children(children, c->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - appends children of parent to linked list.
 * @head: Pointer to head of linked list where children will be appended.
 * @parent: Pointer to node whose children we want to append.
 * Return: Pointer to head of linked list of children.
 */

ll *get_children(ll *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - adds a new node at the end of a linkedlist.
 * @head: pointer to head of linked list.
 * @btnode: const binary tree node to append.
 * Return: pointer to head, or NULL on failure.
 */

ll *append(ll *head, const binary_tree_t *btnode)
{
	ll *m = NULL, *l = NULL;

	m = malloc(sizeof(*m));
	if (m)
	{
		m->node = btnode;
		m->next = NULL;
		if (!head)
			head = m;
		else
		{
			l = head;
			while (l->next)
				l = l->next;
			l->next = m;
		}
	}
	return (head);
}

/**
 * free_list - frees all the nodes in a linked list
 * @head: pointer to the head of list_t linked list
 */

void free_list(ll *head)
{
	ll *p = NULL;

	while (head)
	{
		p = head->next;
		free(head);
		head = p;
	}
}
