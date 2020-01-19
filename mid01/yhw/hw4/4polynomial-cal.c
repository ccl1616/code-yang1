#include <stdio.h>
#include <math.h>

// deg(f(x))=n 求f(m)
int main(void) 
{
    long long int n,m,i = 0; 
    long long int a[101],x[101],y[101]; 
    long long int sum = 0;

    scanf("%lld%lld", &n,&m);

    for(i = 0;i <= n;i ++) //共跑n+1次
    {
        scanf("%lld",&a[n-i]); //高次存到低次 
    }
    
    for (i = n ; n>=0 ; n--) //高次算到低次
    {
        x[n] = pow (m,n);
        y[n] = a[n] * x[n]; //a * x^n
        sum = sum + y[n];
    }
    printf("%lld\n",sum);
    return 0;
}