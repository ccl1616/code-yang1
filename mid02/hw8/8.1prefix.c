#include <stdio.h>
#include <ctype.h>
#include <string.h>
//11224 - Prefix   
double ans;
double cal(void)
{
    char c;
    double op1,op2;
    
    while( isspace(c = getchar()) ) continue;
    //recursive
    if(c == '+'){
        printf("( ");
        op1 = cal();
        printf(" + ");
        op2 = cal();
        printf(" )");
        ans = op1 + op2;
    }
    else if(c == '-'){
        printf("( ");
        op1 = cal();
        printf(" - ");
        op2 = cal();
        printf(" )");
        ans = op1 - op2;
    }
    else if(c == '*'){
        printf("( ");
        op1 = cal();
        printf(" * ");
        op2 = cal();
        printf(" )");
        ans = op1 * op2;
    }
    else if(c == '/'){
        printf("( ");
        op1 = cal();
        printf(" / ");
        op2 = cal();
        printf(" )");
        ans = op1 / op2;
    }
    //basis, if c if beginning with a digit
    else if(isdigit(c)){
        ungetc(c,stdin);
        scanf("%lf",&ans);
        printf("%d",(int)ans);
    }

    return ans;
}

int main(void) 
{ 
    int n;
    scanf("%d",&n);
    while(n --){
        ans = cal();
        if( ans - (int)ans > 0 ) 
            printf(" = %.1f\n",ans);
        else 
            printf(" = %d\n",(int)ans);
    }
    return 0;
}
