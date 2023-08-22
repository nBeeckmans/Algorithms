#include <stdlib.h>

int sort(int* array, int array_size) 
{
    for (int i = 1; i < array_size; i ++) 
    {
        int key = array[i];
        int j = i - 1; 

        while ( j > 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--; 
        }

        array[j + 1] = key; 
    }
}