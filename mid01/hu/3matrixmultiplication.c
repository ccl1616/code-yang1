#include <stdio.h>

int main(void)
{
    int a[11][11],b[11][11],c[11][11]; //for結果矩陣

    int m,n;
    scanf("%d %d\n",&m,&n); //讀 做 矩陣a
    for(int i = 1; i <= m; i ++){ 
        for(int j = 1; j <= n; j ++)
            scanf("%d", &a[i][j]);
    }

    int p,r; //讀 做 矩陣b
    scanf("%d %d\n",&p,&r);
    for(int i = 1; i <= p; i ++){
        for(int j = 1; j <= r; j ++)
            scanf("%d", &b[i][j]);
    }

    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= r; j ++){
            c[i][j] = 0;
            for(int k = 1;k <=n; k ++){
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }                       
    }

    for(int i = 1; i <= m; i ++){ //印出矩陣
        for(int j = 1; j <= r; j ++)
            printf("%d ",c[i][j]);
        printf("\n");
    }

    return 0;
}