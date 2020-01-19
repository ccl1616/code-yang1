#include <stdio.h>
#include <stdlib.h>

#define MAX 1001

int arr[MAX],arrk[MAX];

int main(void){
    int n;
    scanf("%d",&n);

    for(int i = 0; i < n; i ++)
        scanf("%d",&arr[i]);   

    int mul = 0, div = 0, kmin = 0;
    for(int i = 0; i < n; i ++){
        mul = div = 0;
        for(int j = 0; j < n; j ++){
            if((arr[j] % arr[i]) == 0) mul++;
            if((arr[i] % arr[j]) == 0) div++;
        }

        int k = mul - div;
        arrk[i] = k;
        if(i == 0) kmin = k;
        else if(k < kmin) kmin = k;
    } 

    int val = 0, valmin=__INT32_MAX__;
    for(int i = 0; i < n; i ++){
        if(arrk[i]==kmin) {
            val = arr[i];
            if (val < valmin) valmin = val;
        }
    }
    printf("%d\n", valmin);
    return 0;
}
