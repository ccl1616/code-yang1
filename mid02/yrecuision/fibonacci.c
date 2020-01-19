#include<stdio.h>

int fib(int n)
{
    //int ans;
    if(n == 1 || n == 2) return 1;
    else return (fib(n - 1) + fib(n - 2));
    //return ans;
}
int main()
{
    printf("%d\n",fib(7));
    return 0;
}
    