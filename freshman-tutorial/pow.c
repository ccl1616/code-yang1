#include <stdio.h>
void pow(int a,int n) //平方
{
    int i;
    int base=1;

    for(i=1;i<=n;i++)

    {
        base=base*a;
    }
    printf("%d",base);
}

int main()
{
    int a,n;
    scanf("%d %d",&a,&n);
    pow(a,n);
    
    return 0;
}