#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int p;

	if (head == NULL || *head == NULL)
		return (-1);

	tmp = *head;
	p = 0;

	/* 1. Traverse using tmp, not *head, so we don't lose the start */
	while (p < index && tmp != NULL)
	{
		tmp = tmp->next;
		p++;
	}

	/* 2. If index is out of bounds */
	if (tmp == NULL)
		return (-1);

	/* 3. Handle deletion of the head node (index 0) */
	if (index == 0)
	{
		*head = tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	/* 4. Handle deletion of middle or end nodes */
	/* Connect the previous node's 'next' to the current node's 'next' */
	tmp->prev->next = tmp->next;

	/* If there is a next node, connect its 'prev' to the current node's 'prev' */
	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}
