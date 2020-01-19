#include <stdio.h>
// 12574 - New Year
int a[100005];
int main()
{
    int n,i,k;
    int ans = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n; i ++){
        scanf("%d",&a[i]);
    }
    i = a[n];
    int uncle_p = a[i];
    while(i != -1){
        // printf("%d\n",i);
        ans ++;
        i = a[i];
    }
    for(i = 0;i < n; i ++){
        if(a[i] == uncle_p)
            ans ++;
    }
    printf("%d\n",ans-1);
    return 0;
}