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


int *binary_tree_p(const binary_tree_t *tree, int *list, int pos)
{
	if (tree == NULL)
		return (list);

	list[pos] = tree->n;
	binary_tree_p(tree->left, list, pos++);
	binary_tree_p(tree->right, list, pos++);
	return (list);
}

binary_tree_t *search(const binary_tree_t *tree, int ancestor)
{
	search(tree->left, ancestor);
	search(tree->right, ancestor);
	if (tree->n == ancestor)
		return ((binary_tree_t *)tree);
	return ((binary_tree_t *)tree);
}

/**
 * binary_trees_ancestor - a function that finds the lowest common ancestor
 * of two nodes
 * @first: is a pointer to the first node
 * @second:  is a pointer to the second node
 * Return: return a pointer to the lowest common ancestor node of the two
 * given nodes,  no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	int *f_list, *s_list, i, j, ancestor;
	int h_f = binary_tree_height(first), h_s = binary_tree_height(second);

	if (first == NULL || second == NULL)
		return (NULL);

	f_list = malloc(sizeof(int) * h_f);
	s_list =  malloc(sizeof(int) * h_s);

	f_list = binary_tree_p(first, f_list, 0);
	s_list = binary_tree_p(second, s_list, 0);

	for (i = 0; i < h_f; i++)
	{
		for (j = 0; j < h_s; j++)
		{
			if (f_list[i] == s_list[j])
				ancestor = f_list[i];
		}
	}

	return (search(first, ancestor));
}
