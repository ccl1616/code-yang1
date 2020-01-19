#include <stdio.h>
char makephoto(int n,int m,int x) 
{
    int i;

    //case1 
    if(x == 0) { 
        for( i = 1; i <= n; i++) 
            printf("-");
        printf("\n");
    }

    //case2
    else if(x < m) {
        for(i = 1 ; i <= x ; i++)  
            printf("^");
        for(      ; i <= n; i++) 
            printf("-");
        printf("\n");
    }

    //case3
    else if(x == m) {
        for(i = 1 ; i <= m ; i++) 
            printf("^");
        for(      ; i <= n ; i++) 
            printf("-");
        printf("\n");
    }

    //case4
    else if(x > m && x < n) {
        for(i = 1 ; i <= (x-m) ; i++) 
            printf("-");
        for(      ; i <= x ; i++) 
            printf("^");
        for(      ; i <= n ; i++) 
            printf("-");
        printf("\n");
    }

    //case5
    else if(x == n) {
        for(i = 1 ; i <= (n-m) ; i++) 
            printf("-");
        for(      ; i <= n ; i++) 
            printf("^");
        printf("\n");
    }

    //case6
    else if( n< x && x < (n+m)) {
        for(i = 1 ; i <= (x-m) ; i++) 
            printf("-");
        for(      ; i <= n ; i++) 
            printf("^");
        printf("\n");
    }

    //case7
    else if(x >= (n+m) ){
        for(i = 1 ; i <= n ; i++) 
            printf("-");
        printf("\n");
    }
    
    return 0;
}


int main()
{
    int p,n[101],m[101],t[101]; //p = 照片張數 共n人 站立人數m人 t存第“幾”秒的照片
    int i;
    scanf("%d",&p); 

    for(i = 1 ; i <= p ; i++ ) {
        scanf("%d%d%d",&n[i],&m[i],&t[i]); // 每次都存入m,n 從t[0]存到t[p-1]
    }
    
    for(i = 1 ; i <= p ; i++ ) {
        makephoto(n[i],m[i],t[i]);
    }
    return 0;
}
