#include <stdio.h> //191007
#define n 120 //列出小於120的質數
int A[n+1];

int main(void)
{
    int i,j;

    for(i = 0 ; i <= n;i++)
        A[i] = 1;

    for(i = 2 ; i*i <= n ; i++){
        if( A[i] == 1 ){
            for( j = i*i; j <= n ; j+=i ){
			     A[j] = 0;
            }
        }
    }

    for(i = 2;i<=n;i++){
        if( A[i] == 1 )
            printf("%d\n",i);
    }

    return 0;
}
