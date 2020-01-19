#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);

    int n, m, t;
    char arr[101];

    for(int i2 = 0; i2 < T; i2 ++){
        scanf("%d%d%d",&n,&m,&t);
        for(int i = 0; i < n ; i ++)
            arr[i] = '-';

        for(int i = 0; i < t ; i ++)
            arr[i] = '^';

        for(int i = 0; i < t-m ; i ++)
            arr[i] = '-';
        
        for(int i = 0; i < n; i++)
            printf("%c", arr[i]);
        printf("\n");
    }
    return 0;
}