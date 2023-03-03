#include "binary_trees.h"

/**
 * count_node - counts the number of nodes in a tree
 * @tree: is a pointer to the root node of the tree to count
 * Return: size of tree
 */
size_t count_node(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		size += 1;
		size += count_node(tree->left);
		size += count_node(tree->right);
	}
	return (size);
}

/**
 * check_Complete - a function that checks if a binary tree is complete
 * @tree: is a pointer to the root node of the tree to check
 * @index: index
 * @node_count: number of nodes in tree
 * Return: trueor false
 */
bool check_Complete(const binary_tree_t *tree, int index, int node_count)
{
	if (tree == NULL)
		return (true);

	if (index >= node_count)
		return (false);

	return (check_Complete(tree->left, 2 * index + 1, node_count)
			&& check_Complete(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_complete - a function that checks if a binary tree iscomplete
 * @tree:  is a pointer to the root node of the tree to check
 * Return: 1 (yes) or 0(no)
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node_count = count_node(tree);

	if (tree == NULL)
		return (0);

	if (check_Complete(tree, 0, node_count))
		return (1);
	return (0);
}
