#include<stdio.h>
//12453 - Bacteria Division
long long int fast_pow(long long int a, long long int n)
{
    //basis
    if(n == 0) return 1;

    //recursive
    else{
        long long int k = fast_pow(a, n/2);
        if(n%2 == 0) return (k * k) % 10177;
        else return (a * k * k) % 10177;
    }
}

int main()
{
    long long int x,y,n;
    while(scanf("%lld%lld%lld",&x,&y,&n) != EOF){
        long long int ans = 0;
        if(n == 1 || y == 0) 
            ans = x;
        else if(x == 0)
            ans = 0;
        else if(x != 0 && y != 0 && n != 1){
            ans =  (x * fast_pow( y + 1 , n - 1)) % 10177;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

