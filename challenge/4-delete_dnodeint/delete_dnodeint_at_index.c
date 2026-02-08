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

    if (*head == NULL)
        return (-1);

    /* Navigate to the node at the specific index */
    while (tmp != NULL && i < index)
    {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL)
        return (-1);

    /* If deleting the head node */
    if (index == 0)
        *head = tmp->next;

    /* Re-link the 'next' pointer of the previous node */
    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;

    /* Re-link the 'prev' pointer of the next node */
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;

    free(tmp);
    return (1);
}
