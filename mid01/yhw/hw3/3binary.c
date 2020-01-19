#include <stdio.h>
int main(void)
{
    int n,o[11];
    scanf("%d",&n);

    int i = 0; //印出原來數字的binary
    while(n != 0)
    {
        o[i] = (n % 2);//n = 11 1 1 0 1
        n = n / 2;     //     5 2 1 0
        i ++;
    }

    int c,r,q,m; //印出＋1(+c)後的binary
    i = 0,c = 1,m = 0;
    while(c == 1)
    {
        r = (o[i] + c) % 2;
        q = (o[i] + c) / 2;
        o[i] = r;
        if(o[i] == 0){
            m ++;
        }
        c = q;
        i ++;
    }
    
    int j = 10;  //從大位數減回來 遇到0就不輸出
    while(o[j] == 0) j --;
    while(j >= 0) printf("%d",o[j --]);

    printf(" %d",m); //要拿來算進位的m

    return 0;
}