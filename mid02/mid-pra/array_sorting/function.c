#include <stdio.h>
#include "function.h"
#define COLUMN 5
void swap(int *a,int *b);
//12103 - Array Sorting
void sortArray(int R, int (*array)[COLUMN])
{
    int k = 0;
    while(k < R){
        for(int i = 0; i < COLUMN; i ++){
            for(int j = 0; j < COLUMN-i-1; j ++){
                if(array[k][j] > array[k][j+1])
                    swap(&array[k][j],&array[k][j+1]);
            }
        }
        k++;
    }
}

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}