#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: the list to check
 * Return: 0 if no cycle, 1 if cycle
 */

int check_cycle(listint_t *list)
{
	/* browse the list */
	list = list->next;

	if (list->next == NULL)
		return (0);
		
	return (1);
}
