#include <stdio.h>
#include <stdlib.h>
//12515 - Little Brick's Dream

int levelcounter(int pos,int *a)
{
    //int ans = -1;
    int ans = 0;
    for(int i = pos-1; i >= 0; i --){
        if(a[i] > a[pos]){
            ans = pos - 1 - i;
            break;
        }
    }
    return ans;
}

int main()
{
    //n = number of people
    //x = the comfort level we want.
    int n,x;
    scanf("%d %d",&n,&x);

    // a to store input; saving_ans to save the wanted position
    int *a;
    int *saving_ans;
    a = (int*) malloc(sizeof(int)*n);
    saving_ans = (int*) malloc(sizeof(int)*n);

    // j for the index of saving_ans
    //flag for "is their exist comfort case"
    //ans for temporary saving the comfort level
    int j = 0; 
    int flag = 0;
    int max; //trying to save the max

    //input
    for(int i = 0; i < n; i ++){
        scanf("%d",&a[i]);
        int ans = 0;
        if(i == 0)
            max = a[0];

        else if(i == 1){
            if(a[1] > a[0]){
                ans = 1;
                max = a[1];
            }
        }
        else if(i > 1) {
            if(a[i] > max){
                ans = i;
                max = a[i];
            }
            else if(a[i] > a[i-1])
                ans = levelcounter(i,a);
            else if(a[i] < a[i-1])
                ans = 0;
        }

        if(ans == x){
            flag = 1;
            saving_ans[j ++] = i+1;
        }
    }

    if(flag == 0) printf("ouo\n");    
    else {
        printf("%d",saving_ans[0]);
        for(int i = 1; i <= j-1; i ++)
            printf(" %d",saving_ans[i]);
        putchar('\n');
    }
    free(a);
    free(saving_ans);
    return 0;
}