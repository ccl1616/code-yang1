#include<stdio.h>

void binary(int n) //13 6 3 1
{
    int r;
    r = n % 2; //r = 1 0 1 1
    if(n >= 2) binary(n / 2); 

    printf("%d ",r);
}


int main()
{
    int num;
    scanf("%d",&num);
    binary(num);
    //printf("%d",binary(num));
    return 0;
}