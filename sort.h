#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/* Function prototype*/
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insert_beginning(listint_t **list, int value);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void insertion_sort_list(listint_t **list);

void quick_sort(int *array, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
/* Utility function */
void swap(int *a, int *b);
void initialize_node(listint_t *node, int value);
void shell_sort(int *array, size_t size);
#endif
