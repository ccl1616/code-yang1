// hakka's expenses

#include<stdio.h>
#include<math.h>
double x[10], y[10], ans[10];

int main(void)
{
    int t;
    scanf("%d",&t);
    
    for(int i = 0 ; i < t ; i ++){
        scanf("%lf%lf",&x[i],&y[i]);
    }

    for(int i = 0 ; i < t ; i ++){ 
        ans[i] =   (round((y[i]-x[i]) / x[i]*10000)) / 100;
        
        if(ans[i] >= 5.00) 
            printf("%7.2f%% (#`Д´)ﾉ\n", ans[i]);

        else if (ans[i] <= (-5.00) ) 
            printf("%7.2f%% (ゝ∀･)b\n",ans[i]);

        else if (ans[i] == 0) 
            printf("   0.00%% \\^o^/\n");
        
        else printf("%7.2f%% \\^o^/\n",ans[i]);
    }
    return 0;
}