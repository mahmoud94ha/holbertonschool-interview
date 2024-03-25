#include "binary_trees.h"

/**
 *is_bst - Check binary tree.
 *
 *@tree: root pointer.
 *@min: min value.
 *@max: max value.
 *
 *Return: 1 or 0.
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 *binary_tree_height - get binary tree height.
 *
 *@tree: root pointer.
 *
 *Return: height or 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	return (1 + ((left_h > right_h) ? left_h : right_h));
}

/**
 *binary_tree_is_avl - Check binary tree.
 *
 *@tree: root pointer.
 *
 *Return: 1 is valid or 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	if (abs((int) binary_tree_height(tree->left) -
(int) binary_tree_height(tree->right)) > 1)
		return (0);

	if (tree->left && !binary_tree_is_avl(tree->left))
		return (0);

	if (tree->right && !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
