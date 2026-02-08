#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index
 * @head: Double pointer to the head of the list
 * @index: Index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	tmp = *head;

	/* Case 1: Delete the head node (index 0) */
	if (index == 0)
	{
		*head = tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	/* Traverse the list to find the node at the specified index */
	/* We use tmp so the original *head pointer stays at the beginning */
	while (tmp != NULL && i < index)
	{
		tmp = tmp->next;
		i++;
	}

	/* Case 2: Index is out of range */
	if (tmp == NULL)
		return (-1);

	/* Case 3: Delete middle or end node */
	/* Re-link the 'next' pointer of the previous node */
	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;

	/* Re-link the 'prev' pointer of the next node (if it exists) */
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	/* Safe to free the target node now */
	free(tmp);

	return (1);
}
