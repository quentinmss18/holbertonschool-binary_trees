#include "binary_trees.h"

/**
 * depth - Finds depth of the leftmost leaf
 * @tree: Pointer
 *
 * Return: depth
 */
int depth(const binary_tree_t *tree)
{
int d = 0;
while (tree)
{
d++;
tree = tree->left;
}
return (d);
}

/**
 * is_perfect - Checks if tree is perfect
 * @tree: pointer
 * @lvl: current level
 * @d: depth of tree
 *
 * Return: 1 or 0
 */
int is_perfect(const binary_tree_t *tree, int lvl, int d)
{
if (tree == NULL)
return (1);

if (tree->left == NULL && tree->right == NULL)
return (d == lvl + 1);

if (tree->left == NULL || tree->right == NULL)
return (0);

return (is_perfect(tree->left, lvl + 1, d) &&
is_perfect(tree->right, lvl + 1, d));
}

/**
 * binary_tree_is_perfect - Checks if tree is perfect
 * @tree: Pointer to the root
 *
 * Return: 1 if perfect, 0 else
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
int d;

if (tree == NULL)
return (0);

d = depth(tree);
return (is_perfect(tree, 0, d));
}
