#include "sort.h"
/**
 * shell_sort - a function that performs shell sort using Knuth sequence
 * @array: the array
 * @size: the size
 * Return: 0 on success
*/
void shell_sort(int *array, size_t size)
{
    size_t gap = 1;
    size_t i, j;
    int temp;
    while (gap <= size / 3)
    {
        gap = gap * 3 + 1; /* the knuth sequence: n+1 = n * 3 + 1*/
    }
    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;
            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }
            array[j] = temp;
        }
        /*prints the array */
        for (i = 0;i < size; i++)
        {
            printf("%d", array[i]);
            if (i < size - 1)
            {
                printf(", ");
            }
        }        
        putchar('\n');
        gap = (gap - 1) / 3; /* reducing the gap using the knuth sequence*/
    }
}