#include "binary_trees.h"
/**
 * binary_tree_postorder - printing elements of the tree using post-order traversal
 * @tree: tree to check
 * @func: funct used
 * Return: Nothin
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}
	else
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
	}
	func(tree->n);
}
