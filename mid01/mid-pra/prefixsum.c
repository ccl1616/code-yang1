#include<stdio.h>
//prefixsum
long long sum[1000005];
int main()
{
    int n, m, num, left, right;

    scanf("%d",&n); //size of elements

    for(int i = 1; i <= n; i ++){
        scanf("%d",&num);
        sum[i] = sum[i-1] + num;
    }
    scanf("%d",&m);
    for(int i = 0; i < m; i ++){
        scanf("%d%d",&left,&right);
        printf("%lld\n",sum[right]-sum[left-1]);
    }
    
    return 0;
}