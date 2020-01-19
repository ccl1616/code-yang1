#include <stdio.h>
#include <stdlib.h>
//midorimushi

int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main(void)
{
    int t,a;
    int x = 0,y = 0,d = 0,t0 = 0;
    
    while(scanf("%d%d",&t,&a)){
        x += (t - t0) * dir[d][0];
        y += (t - t0) * dir[d][1];
        if(a == 0) d ++;
        if(a == 1) d --;
        if(a == 2) break;
        if(d == 4) d = 0;
        if(d == -1) d = 3;
        t0 = t;
        //printf("%d %d\n",x,y);
    }

    printf("%d %d\n",10*x,10*y);
    return 0;
}

