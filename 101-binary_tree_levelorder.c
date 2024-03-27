#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: binary tree node for the new node to contain.
 * Return: If an error occurs, NULL.
 * Otherwise, a pointer to the new node.
 */

levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *m;

	m = malloc(sizeof(levelorder_queue_t));
	if (m == NULL)
		return (NULL);

	m->node = node;
	m->next = NULL;

	return (m);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: pointer to the head of the queue.
 */

void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *t;

	while (head != NULL)
	{
		t = head->next;
		free(head);
		head = t;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 * @node: binary tree node to print and push.
 * @head: double pointer to the head of the queue.
 * @tail: double pointer to the tail of the queue.
 * @func: pointer to the function to call on @node.
 * Description: Upon malloc failure, exits with a status code of 1.
 */

void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *m;

	func(node->n);
	if (node->left != NULL)
	{
		m = create_node(node->left);
		if (m == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = m;
		*tail = m;
	}
	if (node->right != NULL)
	{
		m = create_node(node->right);
		if (m == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = m;
		*tail = m;
	}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */

void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *t;

	t = (*head)->next;
	free(*head);
	*head = t;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 * level-order traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, func);
		pop(&head);
	}
}
