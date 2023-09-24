#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Insertion Sort algorithm
 * @list: Pointer to the list to be sorted
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1, *prev2, *next1, *next2;

	if (node1 == NULL || node2 == NULL || node1 == node2)
		return;
	prev1 = node1->prev;
	next1 = node1->next;
	prev2 = node2->prev;
	next2 = node2->next;

	if (prev1 != NULL)
	{
		prev1->next = node2;
	}
	else
	{
		*list = node2;
	}
	if (next1 != NULL)
	{
		next1->prev = node2;
	}

	if (prev2 != NULL)
	{
		prev2->next = node1;
	}
	node2->prev = prev1;
	node2->next = node1;
	node1->prev = node2;
	node1->next = next2;
}
/**
 * insertion_sort_list - function that perform insert sort
 * @list: the parameter
 * Return: 0 on success
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *key;
	listint_t *temp;

	if (*list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;

	while (current != NULL)
	{
		key = current;

		while (key->prev != NULL && key->n < key->prev->n)
		{
			swap_nodes(list, key, key->prev);
			key = key->prev;

		}
		current = current->next;
		temp = *list;

		while (temp != NULL)
		{
			printf("%d", temp->n);
			if (temp->next != NULL)
			{
				printf(" <-> ");
				temp = temp->next;
			}
		}
		printf("\n");
	}

void insertion_sort_list(listint_t **list) {
    listint_t *sorted = NULL;  /* Initialize the sorted list */
    listint_t *current = *list;
    listint_t *next;
    listint_t *temp;
    if (list == NULL || *list == NULL || (*list)->next == NULL) {
        return;
    }

    while (current != NULL) {
        next = current->next; /* Store the next node */

        if (sorted == NULL || current->n <= sorted->n) {
            /* Insert current node at the beginning of sorted list */
            current->prev = NULL;
            current->next = sorted;
            if (sorted != NULL) {
                sorted->prev = current;
            }
            sorted = current;
        } else {
            /* Traverse the sorted list to find the correct position */
            temp = sorted;
            while (temp->next != NULL && temp->next->n < current->n) {
                temp = temp->next;
            }

            /* Insert current node after temp */
            current->prev = temp;
            current->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = current;
            }
            temp->next = current;
        }

        current = next;
    }

    *list = sorted; /* Update the head of the list to the sorted list */

}

