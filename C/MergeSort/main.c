#include <stdio.h>
#include "MergeSort.h" 

int main (void) 
{
    int array[10] = {1,6,1,2,8,2,3,0,9,10}; 
    for(int i =0; i < 10; i ++) 
    {
        printf("%i ", array[i]);
    }
    printf("\n"); 
    merge_sort(array, 0 , 9);
    for(int i =0; i < 10; i ++) 
    {
        printf("%i\n", array[i]);
    }
    printf("\n"); 
}
