#include <stdio.h>
#define DEBUG

int main(void)
{
    int balls[5] = {0, 1, 2, 3, 4};
    int k,t1,t2,n1,n2;
    scanf("%d", &k);

    while(k > 0){
        scanf("%d%d",&n1,&n2);
        t1 = balls[n1];
        t2 = balls[n2];
        balls[n1] = t2;
        balls[n2] = t1;
        k--;
    }
    
    int i;
    for (i=0;i<4;i++){
        printf("%d ",balls[i]);
    }
    printf("%d",balls[4]);
    
    #ifdef DEBUG
    freopen("test.in", "r", stdin);
    #endif

    return 0;
}
//02134 02314 42310 