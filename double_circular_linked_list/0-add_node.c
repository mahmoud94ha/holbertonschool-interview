#include <stdlib.h>
#include "list.h"

/**
 *add_node_end - add a new node to the end of a doubly linked list
 *@list: list to modify
 *@str: string to copy into the new node
 *
 *Return: address of the new node, or NULL
 */
List *add_node_end(List **list, char *str)
{
	List *created_node, *temp;

	if (list == NULL || str == NULL)
		return (NULL);

	created_node = malloc(sizeof(List));
	if (created_node == NULL)
		return (NULL);

	created_node->str = strdup(str);
	if (created_node->str == NULL)
	{
		free(created_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		created_node->prev = created_node;
		created_node->next = created_node;
		*list = created_node;
	}
	else
	{
		temp = (*list)->prev;

		created_node->prev = temp;
		created_node->next = *list;
		temp->next = created_node;
		(*list)->prev = created_node;
	}

	return (created_node);
}

/**
 *add_node_begin - add a new node to the end of a doubly linked list
 *@list: list to modify
 *@str: string to copy into the new node
 *
 *Return: adress of the new node, or NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *created_node, *temp;

	if (list == NULL || str == NULL)
		return (NULL);

	created_node = malloc(sizeof(List));
	if (created_node == NULL)
		return (NULL);

	created_node->str = strdup(str);
	if (created_node->str == NULL)
	{
		free(created_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		created_node->prev = created_node;
		created_node->next = created_node;
		*list = created_node;
	}
	else
	{
		temp = (*list)->prev;

		created_node->prev = temp;
		created_node->next = *list;
		temp->next = created_node;
		(*list)->prev = created_node;
		*list = created_node;
	}

	return (created_node);
}
