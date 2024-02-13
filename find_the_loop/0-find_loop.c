#include "lists.h"

/**
 *find_loop_start - Find loop in a linked list
 *@head: Pointer to the head of the linked list
 *
 *Return: Address of the node where the loop starts
 */
listint_t *find_loop_start(listint_t *head)
{
	listint_t *slow_ptr, *fast_ptr;

	if (head == NULL || head->next == NULL)
		return (NULL);

	slow_ptr = head->next;
	fast_ptr = (head->next)->next;

	while (fast_ptr && fast_ptr->next)
	{
		if (slow_ptr == fast_ptr)
		{
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}

			return (slow_ptr);
		}

		slow_ptr = slow_ptr->next;
		fast_ptr = (fast_ptr->next)->next;
	}

	return (NULL);
}
