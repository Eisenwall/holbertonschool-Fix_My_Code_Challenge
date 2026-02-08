if (index == 0)
{
    *head = current->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(current);
    return (1);
}
