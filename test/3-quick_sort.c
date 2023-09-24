#include "sort.h"
/**
 *quick_sort - a function that sort an array recursively using the
 * lomuto Partion scheme
 * @array: List of array element to be sorted
 * @size: size of array(Number of array element
 * Return: None
*/
void quick_sort(int *array, size_t size)
{
int position;
size_t  high;
int pivotindex;
if (size <= 1)
{
return;
}
position = 0;
high = size - 1;
pivotindex = lomuto(array, high, position);
quick_sort(array, pivotindex);
quick_sort(array + pivotindex + 1, size - pivotindex - 1);
}
/**
 *lomuto - a function that partition an array by selecting by any element as
 *the pivot
 *@arr: arr to sort
 *@high: high most element(pivot)
 *@low: left most element of the array
 *Return: the index of the pivot
 */
int lomuto(int *arr, int high, int low)
{
int size;
int pivot;
int position;
int index;
pivot = high;
position = low;
size  = high;
for (index = low; index <= high - 1; index++)
{
if (arr[position] <= pivot)
{
swap(&arr[position], &arr[index]);
print_array(arr, size);
position++;
}
}
swap(&arr[position], &arr[high]);
print_array(arr, size);
return (position);
}
/**
 *swap - a function that change(swap) the position of two element in an array
 *@a: address of the first element to swap
 *@b:Address of the second element to swap
 *Return: None
 */
void swap(int *a, int *b)
{
int tempt = *a;
*a = *b;
*b = tempt;
}
