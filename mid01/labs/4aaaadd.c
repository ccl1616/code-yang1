#include <stdio.h>

int arr[10];
int main(void)
{
    
    for(int i = 1; i <= 9; i ++){
        scanf("%d",&arr[i]);
    }

    int i = 1,j = 0, sum = 0 ;
    if(arr[1] != 1){
        sum += arr[1];
        j = arr[1];

        while( j != 1 ){
            sum += arr[j];
            //i = j;
            j = arr[j];
        }
        //if( arr[j] != arr[1]) sum += arr[j];
    }
    else sum = arr[1];
    
    printf("%d\n",sum);
return 0;
}