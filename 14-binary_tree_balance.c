#include "binary_trees.h"

/**
 * binary_tree_balance - a function that measures the balance factor of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the balance factor
 * Return: number
 * If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	
	left += binary_tree_balance(tree->left);
	right += binary_tree_balance(tree->right);
	if (tree->left)
		left += 1;
	if (tree->right)
		right += 1;	

	return (left - right);
}
