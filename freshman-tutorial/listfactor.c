#include <stdio.h>
//取因數
int main(void)
{
        int num;
        scanf("%d",&num);

        /*int i=1;
        while(i<=num)
        {
            if((num%i==0)&&(num/i>=i))
            {
                printf("%d,",i);
                printf("%d",num/i);
                printf("\n");
            }
        i++;
        }*/

        int i;
        for(i=1;i<=num;i++)
        {
            if((num%i==0)&&(num/i>=i)) //是否整除&商是否大於1
            {
                printf("%d,",i);
                printf("%d",num/i);
                printf("\n");
            }
        }
        
        return 0;
}

    