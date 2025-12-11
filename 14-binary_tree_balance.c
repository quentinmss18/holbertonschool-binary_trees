#include "binary_trees.h"

/**
 * binary_tree_height - Measures tree height
 * @tree: Pointer to the tree
 *
 * Return: Height or 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left = 0;
size_t right = 0;

if (tree == NULL)
return (0);

if (tree->left)
left = 1 + binary_tree_height(tree->left);
if (tree->right)
right = 1 + binary_tree_height(tree->right);

if (left > right)
return (left);
return (right);
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: Pointer to the tree
 *
 * Return: balance factor or 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
int left = 0;
int right = 0;

if (tree == NULL)
return (0);

if (tree->left)
left = (int)binary_tree_height(tree->left) + 1;
if (tree->right)
right = (int)binary_tree_height(tree->right) + 1;

return (left - right);
}
