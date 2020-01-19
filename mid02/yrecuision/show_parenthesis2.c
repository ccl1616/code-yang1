#include<stdio.h>
//show_parenthesis
int showpar(int n)
{
    int prev;
    if(n > 1){
        if(n % 2 == 1){
            printf("(");
            prev = showpar(n - 1);
            printf(")*%d",n);
            return prev * n;
        }
        else{
            prev = showpar(n - 1);
            printf("+%d",n);
            return prev + n;
        }
    }
    //n = 1;
    else {
        printf("%d",n);
        return 1;
    }

}

int main()
{
    int n;
    scanf("%d",&n);
    printf("=%d",showpar(n));
    return 0;
}