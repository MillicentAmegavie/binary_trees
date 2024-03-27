#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
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
 * push - Pushes a node to the back of a levelorder_queue_t queue.
 * @node: binary tree node to print and push.
 * @head: double pointer to the head of the queue.
 * @tail: double pointer to the tail of the queue.
 * Description: Upon malloc failure, exits with a status code of 1.
 */

void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *m;

	m = create_node(node);
	if (m == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = m;
	*tail = m;
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: double pointer to the head of the queue.
 */

void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *t;

	t = (*head)->next;
	free(*head);
	*head = t;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to traverse.
 * Return: If the tree is NULL or not complete, 0.
 * Otherwise, 1.
 * Description: Upon malloc failure, exits with a status code of 1.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char f = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (f == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			f = 1;
		if (head->node->right != NULL)
		{
			if (f == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			f = 1;
		pop(&head);
	}
	return (1);
}
