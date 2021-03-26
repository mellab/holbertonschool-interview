#include "binary_trees.h"

/**
 * new_node - create new node
 * @val: node value
 * @parent: parent node
 *
 * Return: A new node
 */
avl_t *new_node(int val, avl_t *parent)
{
	avl_t *node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->n = val;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * convert_to_avl - converts array to AVL tree
 * @array: sorted array to be converted
 * @low: low index of @array
 * @high: high index of @array
 * @parent: parent node
 *
 * Return: new AVL tree
 */

avl_t *convert_to_avl(int *array, size_t low, size_t high, avl_t *parent)
{
	size_t middle;
	avl_t *root;

	if (high == ULONG_MAX || low > high)
		return (NULL);
	middle = low + (high - low) / 2;
	root = new_node(array[middle], parent);
	if (!root)
		return (NULL);

	root->left = convert_to_avl(array, low, middle - 1, root);
	root->right = convert_to_avl(array, middle + 1, high, root);
	return (root);
}

/**
 * sorted_array_to_avl - sorted array to AVL tree
 * @array: sorted array to be converted
 * @size: size of @array
 *
 * Return: new AVL tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || !size)
		return (NULL);
	return (convert_to_avl(array, 0, size - 1, NULL));
}
