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
    dlistint_t *saved_head;
    dlistint_t *tmp;
    unsigned int i = 0;

    if (head == NULL || *head == NULL)
        return (-1);

    saved_head = *head;
    tmp = *head;

    while (i < index && tmp != NULL)
    {
        tmp = tmp->next;
        i++;
    }

    if (tmp == NULL)
        return (-1);

    *head = tmp;

    if ((*head)->prev != NULL)
        (*head)->prev->next = (*head)->next;

    if ((*head)->next != NULL)
        (*head)->next->prev = (*head)->prev;

    if (index == 0)
        saved_head = (*head)->next;

    free(*head);
    *head = saved_head;

    return (1);
}
