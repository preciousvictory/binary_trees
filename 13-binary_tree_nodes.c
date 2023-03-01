#include "binary_trees.h"

/**
 * binary_tree_nodes - function that counts the nodes with at least
 * 1 child in a binary tree
 * @tree: is a pointer to the root node of the tree to count the number ofnodes
 * If tree is NULL, the function must return 0. A NULL pointer is not a node
 * Return: size
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	if (tree)
	{
		count += binary_tree_nodes(tree->left);
		count += binary_tree_nodes(tree->right);
		if (tree->left || tree->right)
			count += 1;
	}

	return (count);
}
