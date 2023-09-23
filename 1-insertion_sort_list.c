#include "sort.h"

/**
 * swap_nodes - a function that swap nodes in double linked list
 * @list: the list
 * @node1: the first nodes
 * @node2: the second nodes
 * Return: 0 on success
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
 * insert_sort_list - function that perform insert sort
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
		key= current;

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
}
/**
 * insert_beginning - function that insert node at the beginnig
 * @list: the pointer
 * @value: the new node you are adding t to the beginnig
 * Return: 0 on success
 */
void insert_beginning(listint_t **list, int value)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	initialize_node(new_node, value);

	if (*list == NULL)
	{
		*list = new_node;
		return;
	}

	new_node->next = *list;
	(*list)->prev = new_node;
	*list = new_node;
}
void initialize_node(listint_t *node, int value)
{
	int *n_ptr = (int *)&(node->n);
	*n_ptr = value;
	node->prev = NULL;
	node->next = NULL;
}
