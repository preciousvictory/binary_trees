#include "binary_trees.h"

/**
 * binary_trees_ancestor - a function that finds the lowest common ancestor
 * of two nodes
 * @first: is a pointer to the first node
 * @second:  is a pointer to the second node
 * Return: return a pointer to the lowest common ancestor node of the two
 * given nodes,  no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *f_anc, *s_anc;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	f_anc = first->parent;
	s_anc = second->parent;

	if (first == s_anc || !f_anc || (!f_anc->parent && s_anc))
		return (binary_trees_ancestor(first, s_anc));
	else if (!s_anc || second == f_anc || (!s_anc->parent && f_anc))
		return (binary_trees_ancestor(f_anc, second));
	return (binary_trees_ancestor(f_anc, s_anc));
}
