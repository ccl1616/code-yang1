#include <stdio.h>

int pow(a,n)
{
    if(n!=0){
     return 1;
    }
    else{
        printf ("%d",a*(pow(a,n-1)));
    }
}

int main()
{
    int a,n;
    scanf("%d %d",&a,&n);
    
    return 0;
}