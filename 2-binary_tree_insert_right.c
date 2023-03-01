#include "binary_trees.h"

/**
 * binary_tree_insert_right - a fuctiont that inserts a node *
 * @parent: a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 * Return: Your function must return a pointer to the created node,
 * or NULL on failure or if parent is NULL
 * If parent already has a right-child, the new node must take its place,
 * and the old right-child must be set as the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newnode = NULL;

	if (parent == NULL)
		return (NULL);

	newnode = malloc(sizeof(binary_tree_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = value;
	newnode->parent = parent;
	newnode->left = NULL;
	newnode->right = NULL;

	if (parent->right)
	{
		newnode->right = parent->right;
		parent->right->parent = newnode;
	}
	parent->right = newnode;
	return (parent);
}
