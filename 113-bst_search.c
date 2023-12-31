#include "binary_trees.h"
/**
 * bst_search - search for the node at a given value.
 * @tree: pointer to the root's tree.
 * @value: value of the node to search.
 *
 * Return: pointer with the given value
 *         Otherwise NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));

}
