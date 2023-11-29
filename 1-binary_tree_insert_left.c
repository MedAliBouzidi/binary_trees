#include "binary_trees.h"

/**
 * *binary_tree_insert_left - inserts a node as the left-child of another node
 *
 * @parent: parent node
 * @value: node value
 *
 * Return: a pointer to the created node,
 *		or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->right = NULL;
	new->left = NULL;

	if (parent->left == NULL)
		parent->left = new;
	else
	{
		parent->left->parent = new;
		new->left = parent->left;
		parent->left = new;
	}

	return (new);
}
