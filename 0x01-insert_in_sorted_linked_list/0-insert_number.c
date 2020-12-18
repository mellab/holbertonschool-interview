#include "lists.h"

/**
 * insert_node - function for inserting node into sorted linked list
 * @head: pointer to head
 * @number: number to insert
 *
 * Return: pointer to the node
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node, *temp;

	temp = malloc(sizeof(listint_t));
	if (!temp)
		return (NULL);
	temp->n = number;

	if (!*head || number < (*head)->n)
	{
		temp->next = *head;
		*head = temp;
		return (temp);
	}
	for (node = *head; node->next && node->next->n <= number; node = node->next)
		;
	temp->next = node->next;
	node->next = temp;
	return (temp);
}
