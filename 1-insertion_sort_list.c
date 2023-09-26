#include "sort.h"
/**
 * insertion_sort_list - function that perform insert sort
 * @list: the parameter
 * Return: 0 on success
 */
void insertion_sort_list(listint_t **list)
{
listint_t *sorted;
listint_t *current;
listint_t *next;
listint_t *temp;
sorted = NULL;
current = *list;
if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;
while (current != NULL)
{
next = current->next;
if (sorted == NULL || current->n <= sorted->n)
{
current->prev = NULL;
current->next = sorted;
if (sorted != NULL)
	sorted->prev = current;
sorted = current;
}
else
{
temp = sorted;
while (temp->next != NULL && temp->next->n < current->n)
{
temp = temp->next;
}
current->prev = temp;
current->next = temp->next;
if (temp->next != NULL)
	temp->next->prev = current;
temp->next = current;
}
*list = sorted;
temp = *list;
print_list(temp);
current = next;
}
}
