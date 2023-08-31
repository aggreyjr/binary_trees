#include "binary_trees.h"
/**
 * binary_tree_insert_left - adding a node to the left of the parent
 * if it exists it should move down one level and add the new node first
 * @parent: parent to specified node
 * @value: node value
 * Return: NULL incase of failure or the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
