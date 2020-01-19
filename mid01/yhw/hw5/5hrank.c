#include <stdio.h>
#include <stdlib.h>

long int a[2000],b[2000],ans[2000],temp; //a : input value, seq : make it in sequence

int main(void)
{
    int n;
    scanf("%d",&n);
    
    for(int i = 0 ; i < n ; i ++ ){
        scanf("%ld", &a[i]); //讀入a[i]
        b[i] = a[i]; 
    }

    for(int i = 0 ; i < n  ; i ++ ){ //用b重排大小 小排到大
        for(int j = i ; j < n ; j ++){ 
            if(b[j] < b[i]){
                temp = b[j];
                b[j] = b[i];
                b[i] = temp;
            }
        }
    }
    //qsort(a, n, sizeof(long int), cmp);
    
    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ; j < n ; j ++){
            for(int k = 0 ; k < n ; k ++){
                if(a[i] == b[k]) {
                    ans[i] = k+1;
                    break;
                }
            }
        }
    }

    for(int i = 0 ; i < n-1 ; i ++ ){
        printf("%ld ",ans[i]);
    }
    printf("%ld",ans[n-1]);
    printf("\n");
    return 0;
}
