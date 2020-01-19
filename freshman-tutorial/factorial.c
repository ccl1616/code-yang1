#include <stdio.h>
void fac(int n) //連乘
{
    int i;
    int total=1;

    for(i=1;i<=n;i++)
        total=total*i;
    printf("%d",total);
}

//solution2 //by recursion
int fac2(int n)
{
    if(n > 0) ans = n * fac2(n - 1);
    else ans = 1;
    return ans;
}


int main()
{
    int num;
    scanf("%d",&num);
    fac(num);
    
    return 0;
}