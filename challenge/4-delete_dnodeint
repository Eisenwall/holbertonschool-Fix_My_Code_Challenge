#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* Case 1: Delete the head node */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* Traverse to the node at the specified index */
	for (i = 0; current != NULL && i < index; i++)
		current = current->next;

	/* Case 2: Index out of range */
	if (current == NULL)
		return (-1);

	/* Case 3: Delete middle or tail node */
	/* Connect previous node to next node */
	if (current->prev != NULL)
		current->prev->next = current->next;

	/* Connect next node back to previous node */
	if (current->next != NULL)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
