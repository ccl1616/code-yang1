#include <stdio.h>
#include <stdlib.h>

long int a[2000],ans[2000]; //a : input value, seq : make it in sequence

int main(void)
{
    int n;
    char ch;
    scanf("%d",&n);
    
    for(int i = 0 ; i < n ; i ++ ){
        scanf("%ld", &a[i]); //讀入a[i]
    }

    int count;
    for(int i = 0 ; i < n  ; i ++ ){ 
        count = 0;
        for(int j = 0 ; j < n  ; j ++ )
            if(a[i] > a[j]) count++;
        ans[i] = count;
    }
    
    for(int i = 0 ; i < n-1 ; i ++ ){
        printf("%ld ",ans[i]+1);
    }
    printf("%ld",ans[n-1]+1);
    printf("\n");
    return 0;
}
