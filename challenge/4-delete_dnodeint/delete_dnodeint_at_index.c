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
	dlistint_t *tmp = *head;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	/* Traverse to the node at the specified index */
	while (tmp != NULL && i < index)
	{
		tmp = tmp->next;
		i++;
	}

	/* Index is out of range */
	if (tmp == NULL)
		return (-1);

	/* If we are deleting the head node */
	if (index == 0)
		*head = tmp->next;

	/* Bridge the gap: Previous node points to Next node */
	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;

	/* Bridge the gap: Next node points back to Previous node */
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}
