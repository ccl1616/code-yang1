#include <stdio.h>

int main(void)
{
    //input=123.456
    float n,n1000;
    scanf ("%f",&n);
    n1000=n*1000;
    int num=(int)n1000;
    int left,right;
    left=num/1000; //123
    right=num%1000; //456

    int a,b,c,d,e,f;
    a=left/100; //1
    b=left/10%10; //12-10=2 2%10=2
    c=left%10; //3
    
    d=right/100; //4
    e=right/10%10; //45-40=5 
    f=right%10; //6

    float k;
    k=100*c+10*b+a+0.1*f+0.01*e+0.001*d; //cba.fed
    
    float m;
    m=n+k;
    printf("%3.3f",m);
    return 0;
}
