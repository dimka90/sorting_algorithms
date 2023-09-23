#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Insertion Sort algorithm
 * @list: Pointer to the list to be sorted
 */
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

