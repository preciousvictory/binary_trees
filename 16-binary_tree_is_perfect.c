#include "binary_trees.h"

/**
 * depth - Returns depth of leftmost leaf.
 * @tree: is a pointer to the root node of the tree to check
 * Return: num
 */
int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect - // Check if the tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * @d: depth of the tree;
 * @level: the level on the tree it's currently on
 * Return: true or false
 */
bool is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return (false);

	return (is_perfect(tree->left, d, level + 1) &&
			is_perfect(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - a function that checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: numebr
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	bool ans;
	int d = depth(tree);

	ans = is_perfect(tree, d, 0);
	if (ans)
		return (1);
	return (0);
}
