#include "binary_trees.h"

/**
 * binary_tree_insert_left - a function that inserts a node as the
 * left-child of another node
 *
 * @parent:  is a pointer to the node to insert the left-child in
 * @value: is the value to store in the new node
 *
 * Return: function must return a pointer to the created node,
 * or NULL on failure or if parent is NULL
 * If parent already has a left-child, the new node must take its place, and
 * the old left-child must be set as the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode;

	if (parent == NULL)
		return (NULL);

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;

	if (parent->left == NULL)
		parent->left = newnode;
	else
	{
		newnode->n = parent->left->n;
		parent->left->n = value;
		parent->left->left = newnode;
	}
	return (parent);
}
