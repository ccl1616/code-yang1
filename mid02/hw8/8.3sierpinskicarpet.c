//12459 - Sierpinski Carpet
#include<stdio.h>
#include<math.h>
long long int num,ans;

long long int count(int a)
{
    //basis
    if(a == 1) ans = 1;
    //recursion
    else ans = count(a - 1) + pow(8, a - 1);
    return ans;
}
int main()
{
    scanf("%lld",&num);
    if(num == 0) printf("0\n");
    else printf("%lld\n",count(num));
    return 0;
}