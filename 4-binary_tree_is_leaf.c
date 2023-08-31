#include "binary_trees.h"
/**
 * binary_tree_is_leaf - how to know if a node is a leaf, meaning that the node
 * does not have any child neither on the left nor right
 * @node: node to search
 * Return: 1 if it is a leaf or 0 if it is not
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
