#include "binary_trees.h"
/**
 * binary_tree_delete - freeing an entire tree using recursion which frees the node
 * when the node's left and right are NULL
 * @tree: tree for freeing
 * Return: nothin
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		if (tree != NULL)
		{
			binary_tree_delete(tree->left);
			binary_tree_delete(tree->right);
		}
		free(tree);
	}

}
