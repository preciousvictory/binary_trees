#include "binary_trees.h"

/**
 * binary_tree_leaves - a function that counts the leaves in a binary tree
 * @tree:  is a pointer to the root node of the treeto count thenumber ofleaves
 * If tree is NULL, the function must return 0, A NULL pointer is not a leaf
 * Return: number of child
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		count++;
	if (tree->right != NULL)
		count++;

	return (count);
}
