#include <stdio.h>
#include <stdlib.h>

// by changing the *array pass to this function
void malloc_array(int **array, int array_size)
{
    *array = (int*) malloc(sizeof(int)*array_size);
}

// by return
int** malloc_ptr(int array_size)
{
    int **temp; 
    temp = (int**) malloc(sizeof(int*)*array_size);
    return temp;
}

void pointer_ptr_to_array(int *array, int **ptr,int N)
{
    for(int i = 0; i < N; i ++){
        int k;
        k = i*(i+1) / 2;
        *(ptr+i) = array+k;
    }
}