#include "sort.h"
/**
 * selection_sort -  a function that sort numbers using
 * selection sort
 * @array: array of element to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
size_t sort_pass;
size_t index;
if (size < 2)
	return;

for (sort_pass = 0; sort_pass < size - 1; sort_pass++)
{
size_t minimum_num = sort_pass;

for (index = sort_pass + 1; index < size; index++)
{

	if (array[index] < array[minimum_num])
	{

	minimum_num = index;
	}
}
	if (minimum_num != sort_pass)

	{
		int tempt = array[sort_pass];

		array[sort_pass] = array[minimum_num];
		array[minimum_num] = tempt;
		print_array(array, size);
	}
}
}
