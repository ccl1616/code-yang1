#include<stdio.h>

int main(void)
{
    int m,n,q;
    char ch;
    scanf("%d%d%d",&m,&n,&q);

    char a[1005][1005];
    //存入二維陣列
    for(int i = 1 ; i <= m ; i ++){  
        for(int j = 1 ; j <= n ; j ++){ 
            scanf(" %c",&a[i][j]); 
        }
    }

    //存入交換方式
    //讓最後一組是t[1][0]和t[1][1] 倒著存回來 因為要從後面的先交換回去
    int t[1005][2];
    for(int i = q ; i >= 1  ; i -- ){ 
        for(int j = 0 ; j <= 1 ; j ++ ){
            scanf("%d",&t[i][j]);
        }
    }
    
    //交換
    char temp;
    int x, y, j;
    for(int i = 1 ; i <= q ; i ++ ){
        //x y為交換的兩組
        x = t[i][0]; 
        y = t[i][1];

        //每次交換一個row
        for(int j = 1 ; j <= m ; j ++){
            temp = a[j][x];
            a[j][x] = a[j][y];
            a[j][y] = temp;
        }
    }
    
    //output
    for(int i = 1; i <= m; i ++){ 
        for(int j = 1; j <= n; j ++)
            printf("%c", a[i][j]); 
    }
    printf("\n");

    return 0;
}