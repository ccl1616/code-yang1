#include<stdio.h>
//show_parenthesis
void showpar(int n)
{
    if(n > 1){
        if(n % 2 == 1){
            printf("(");
            showpar(n - 1);
            printf(")*%d",n);
        }
        else{
            showpar(n - 1);
            printf("+%d",n);
        }
    }
    //n = 1;
    else printf("%d",n);

}

int main()
{
    int n;
    scanf("%d",&n);
    showpar(n);
    return 0;
}