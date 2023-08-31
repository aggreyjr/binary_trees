#include "binary_trees.h"

/**
 * array_to_bst - inserting a new node in a Binary Search Tree
 * @array: array used
 * @size: array size
 *
 * Return: NULL if no common ancestor found
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *new_node = NULL;

	unsigned int index;

	for (index = 0; index < size; index++)
	{
		bst_insert(&new_node, array[index]);
	}
	return (new_node);
}
