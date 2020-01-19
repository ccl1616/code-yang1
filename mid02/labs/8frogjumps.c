#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//12481 - Frog Jumping
#define min(a, b) (a < b ? a : b)
int h[30];
int n,ans;
int cost[30],t[30];
//t[] = the min step to the place
//cost[] = the min cost to the place
// get the t[] and cost[] for each stone
void jump(int pos)
{
    if(pos == 1){
        cost[1] = abs(h[1] - h[0]);
        t[1] = 1;
    }
    else{
        int c2 = cost[pos-2] + abs( h[pos]-h[pos-2] );
        int c1 = cost[pos-1] + abs( h[pos]-h[pos-1] );
        if(c2 > c1) {
            cost[pos] = c1;
            t[pos] = t[pos-1] + 1;
        }
        else if(c2 < c1){
            cost[pos] = c2;
            t[pos] = t[pos-2] + 1;
        }
        else{
            cost[pos] = c1;
            t[pos] = min(t[pos-1],t[pos-2]) + 1; 
        }
    }
    if (pos+1 < n)
        jump(pos+1);
}

int main(void) { 
    scanf("%d",&n);
    for(int i = 0; i < n; i ++) scanf("%d",&h[i]);
    jump(1);
    printf("%d %d\n",cost[n-1],t[n-1]);
    return 0;
}
