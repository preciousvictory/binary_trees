#include "binary_trees.h"

/**
 * binary_tree_insert_left -  creates a binary tree node
 * @parent: parent of root
 * @value: value of the tree
 * Return: a pointer to the created node,or NULL on failure or if parent isNULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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

	if (parent->left)
	{
		newnode->left = parent->left;
		parent->left->parent = newnode;
	}
	parent->left = newnode;
	return (newnode);
}
