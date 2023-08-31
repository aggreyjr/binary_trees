#include "binary_trees.h"

/**
 * binary_tree_ancestor - finding the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: NULL if not a common ancestor found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *pa_fi, *pa_se;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	pa_fi = first->parent;
	pa_se = second->parent;

	if (first == pa_se || !pa_fi || (!pa_fi->parent && pa_se))
		return (binary_trees_ancestor(first, pa_se));

	else if (second == pa_fi || !pa_se || (!pa_se->parent && pa_fi))
		return (binary_trees_ancestor(second, pa_fi));

	return (binary_trees_ancestor(pa_fi, pa_se));
}
