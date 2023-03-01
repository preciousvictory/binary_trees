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
 * binary_tree_balance - a function that measures the balance factor of
 * a binary tree
 * @tree: pointerto the root node of the tree to measure the balancefactor
 * Return: number
 * If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	if (tree->left)
		left += 1;
	if (tree->right)
		right += 1;

	return (left - right);
}
