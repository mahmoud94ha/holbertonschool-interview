#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * sort_heap - Sorts a binary heap tree
 *
 * This function sorts the binary heap tree
 *
 * @current: The root node of the binary heap tree to be sorted
 * Return: A pointer to the sorted binary heap tree
 */
heap_t *sort_heap(heap_t *current)
{
	int temp;

	while (current->left || current->right)
	{
		if (!current->right || current->left->n > current->right->n)
		{
			temp = current->n;
			current->n = current->left->n;
			current->left->n = temp;
			current = current->left;
		}
		else if (!current->left || current->left->n < current->right->n)
		{
			temp = current->n;
			current->n = current->right->n;
			current->right->n = temp;
			current = current->right;
		}
	}

	return (current);
}

/**
 * preorder_traversal - Performs preorder traversal
 *
 * This function performs a preorder traversal of a binary tree
 *
 * @root: The root node of the binary tree
 * @node: A double pointer to store the found node
 * @target_level: The target level to find the node
 * @current_level: The current level during traversal
 */
void preorder_traversal(heap_t *root, heap_t **node, size_t
target_level, size_t current_level)
{
	if (!root)
		return;
	if (current_level == target_level)
		*
		node = root;
	current_level++;
	if (root->left)
		preorder_traversal(root->left, node, target_level, current_level);
	if (root->right)
		preorder_traversal(root->right, node, target_level, current_level);
}

/**
 * get_tree_height - Calculates the height
 *
 * This function calculates the height of a given binary tree.
 *
 * @tree: The root node of the binary tree
 * Return: The height of the binary tree
 */
static size_t get_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	left_height = tree->left ? 1 + get_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + get_tree_height(tree->right) : 0;
	return (left_height > right_height ? left_height : right_height);
}

/**
 * heap_extract - Extracts the root value
 *
 * This function extracts the root value from a binary heap tree
 *
 * @root: A double pointer to the root node of the binary heap tree
 * Return: The extracted value from the root of the binary heap tree
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *current, *node;

	if (!root || !*root)
		return (0);

	current = *root;
	extracted_value = current->n;

	if (!current->left && !current->right)
	{
		*root = NULL;
		free(current);
		return (extracted_value);
	}

	preorder_traversal(current, &node, get_tree_height(current), 0);
	current = sort_heap(current);
	current->n = node->n;

	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;

	free(node);
	return (extracted_value);
}
