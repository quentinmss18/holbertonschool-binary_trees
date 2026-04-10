#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: A pointer to the node to insert the right-child in
 * @value: The value to store in the new node
 *
 * Return: A pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	/* Utilisation de la fonction du fichier 0-binary_tree_node.c */
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);

	/* Si le parent a déjà un enfant à droite */
	if (parent->right != NULL)
	{
		/* L'ancien enfant devient le fils droit du nouveau nœud */
		new_node->right = parent->right;
		/* On met à jour le parent de l'ancien enfant */
		new_node->right->parent = new_node;
	}

	/* Le nouveau nœud devient officiellement le fils droit du parent */
	parent->right = new_node;

	return (new_node);
}
