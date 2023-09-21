#include "sort.h"
/**
*bubble_sort - a functioin that sort numbers in an array using
*bubble sort
*@array: an array of numbers to sort
*@size: length of array to perfor sort on
*Return: None
*/
void bubble_sort(int *array, size_t size)
{
size_t tempt;
size_t index;
size_t sort_pass;

if (size < 2)
	return;
for (index = 0; index < size; index++)
{
for (sort_pass = 0; sort_pass < size - 1 - index; sort_pass++)
{
if (array[sort_pass] > array[sort_pass + 1])
{
tempt = array[sort_pass];

array[sort_pass] = array[sort_pass + 1];
array[sort_pass + 1] = tempt;
print_array(array, size);
}
}
}
}
