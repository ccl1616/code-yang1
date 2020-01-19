#include <stdio.h>
#include <stdlib.h>
// 11773 - Integer pointer array
int main()
{
    int size,offset,k;
    int **ptr,*array;
    scanf("%d %d",&size,&offset);
    k = (size+1)*size/2 ;

    array = (int*) malloc( sizeof(int) * k );
    for(int i = 0; i < k ; i++)
        array[i] = i;

    //printf("hi\n");
    ptr = (int**) malloc( sizeof(int*) * size );
    /*for(int i = 0; i < k; i ++){
        printf("%d\n",*(array+i) );
    }*/

    for(int i = 0; i < size; i ++){
        int j = (i+1)*i/2;
        ptr[i] = &array[j];
    }
    //printf("hi2\n");

    for(int i = 0; i < size; i ++){
        printf("%d\n",*(ptr[i])+offset );
    }
    
    free(ptr);
    free(array);
    return 0;
}