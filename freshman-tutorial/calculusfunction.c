#include<stdio.h>
int cal(int n1,int n2,char op);

int main()
{
    int num1,num2,a;
    char opi;
    scanf("%d%d %c",&num1,&num2,&opi);
    printf("%d",cal(num1,num2,opi)); //呼叫addfunction

    //printf("%f",pow(num1,num2));
    return 0;
}


int cal(int n1,int n2,char op) //說明add function
{
    if(op=='+')
    {
        return n1+n2;
    }
    else if (op=='-')
    {
        return n1-n2;
    }
    else if (op=='*')
    {
        return n1*n2;
    }
    else
    {
        return n1/n2;
    }
    
}
