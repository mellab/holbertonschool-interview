#include "lists.h"

/**
 * check_cycle - check if the linked list is cyclical
 * @list: pointer to head of the list
 *
 * Return: 1 if is cyclical, otherwise return 0
 */

int check_cycle(listint_t *list)
{
	listint_t *fast, *slow;

	fast = slow = list;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return (1);
	}
	return (0);
}
