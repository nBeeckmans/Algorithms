#include "MergeSort.h"

void merge(int *array, int first, int middle, int last)
{
    int left_length = middle - first + 1;
    int right_length = last - middle;

    int left_array[left_length];
    int right_array[right_length];

    int i = 0, j = 0, k = first;

    for (; i < left_length; i++)
    {
        left_array[i] = array[i];
    }

    for (; i < right_length; i++)
    {
        right_array[i] = array[i];
    }

    i = 0;

    while ( i < left_length && j < right_length)
    {
        if (left_array[i] <=  left_array[j])
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < left_length)
    {
        array[k] = left_array[i];
        i++, k++;
    }

    while (j < right_length)
    {
        array[k] = left_array[j];
        j++, k++;
    }
}

void merge_sort(int *array, int first, int last) 
{
    if (first >= last) 
    {
        return;
    }

    int middle = ( first + last ) / 2; 
    merge_sort(array, first, middle);
    merge_sort(array, middle+1, last); 

    merge(array, first, middle, last);
}

