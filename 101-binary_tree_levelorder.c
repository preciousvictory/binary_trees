#include "binary_trees.h"

/**
 * binary_tree_height - function that calculates the height of tree
 * @tree: is a pointer to the root node of the tree to check
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		l = 1 + binary_tree_height(tree->left);
	if (tree->right)
		r = 1 + binary_tree_height(tree->right);

	if (l > r)
		return (l);
	return (r);
}

/**
 * printCurrentLevel - Print nodes at a current level
 * @tree: is a pointer to the root node of the tree to check
 * @level: level
 * @func:  is a pointer to a function to call for each node.
 */
void printCurrentLevel(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		printCurrentLevel(tree->left, level - 1, func);
		printCurrentLevel(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - a function that goes through a binary tree
 * using level-order traversal
 * @tree: is a pointer to the root node of the tree to traverse
 * @func: is a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int h = binary_tree_height(tree) + 1, i;

	if (tree == NULL || func == NULL)
		return;

	for (i = 1; i <= h; i++)
		printCurrentLevel(tree, i, func);
}
