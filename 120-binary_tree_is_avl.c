#include "binary_trees.h"

/**
 * binary_tree_is_avl - inserting a new node in a Binary Search Tree
 * @tree: array used
 *
 * Return: NULL if no common ancestor was found
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{

	if (!tree)
	{
		return (0);
	}
	if (!tree->left && !tree->right)
		return (1);

	if (binary_tree_is_bst(tree) != 1 || binary_tree_balance(tree) != 1)
		return (0);

	if (binary_tree_is_bst(tree->left) != 1 ||
		binary_tree_balance(tree->left) != 1)
		return (0);

	if (binary_tree_is_bst(tree->right) != 1 ||
		binary_tree_balance(tree->right) != 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_bst - finding the lowest common ancestor of two nodes
 * @tree: pointer to the first node
 *
 * Return: If no common ancestor was found return NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	if (check_less_greater(tree->left, tree->n, 1) &&
		check_less_greater(tree->right, tree->n, 2))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * check_less_greater - verifying if node is (less or greater) than root value
 * @tree: pointer to the first node
 * @n: root value
 * @flag: switch to active less or greater mode
 * Return: 1 if are right or 0 if failes
 */
int check_less_greater(const binary_tree_t *tree, int n, int flag)
{
	int left, right;

	if (tree == NULL)
		return (1);
	if (flag == 1)
	{
		if (tree->n < n)
		{
			left = check_less_greater(tree->left, n, flag);
			right = check_less_greater(tree->right, n, flag);
			if (left != 0 && right != 0)
			{
				return (1);
			}
		}
	}
	if (flag == 2)
	{
		if (tree->n > n)
		{
			left = check_less_greater(tree->left, n, flag);
			right = check_less_greater(tree->right, n, flag);
			if (left != 0 && right != 0)
			{
				return (1);
			}
		}
	}
	return (0);
}

/**
 * binary_tree_height - Measuring height of a binary tree
 * @tree: pointer to the root node of the tree to be measured
 *
 * Return: 0 tree is NULL, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	left = 1 + binary_tree_height(tree->left);
	right = 1 + binary_tree_height(tree->right);

	if (left > right)
		return (left);
	return (right);
}

/**
 * binary_tree_balance - Measuring the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 *
 * Return: 0 if tree is NULL, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0, count;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);

	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	count = left_height - right_height;
	if (count >= -1 && count <= 1)
		return (1);

	return (0);
}
