#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// 12071 - Traveling mail carrier
int a[10][10];
int vplace[11];
int amount_visited;
int min_dis = __INT_MAX__;
int now_dis; // distance
int n;

void dfs(int pos)
{
    if(amount_visited == n){
        //now_dis += a[pos][0];
        if(now_dis + a[pos][0] < min_dis)
            min_dis = now_dis + a[pos][0];
    }
    for(int i = 0; i < n; i ++){
        if(!vplace[i]){
            vplace[i] = 1;
            amount_visited ++;
            now_dis += a[pos][i];
            dfs(i);
            vplace[i] = 0;
            amount_visited --;
            now_dis -= a[pos][i];
            //now_dis -= a[pos][0];
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        //vplace[i] = 0;
        for(int j = 0; j < n; j ++)
            scanf("%d",&a[i][j]);
    }
    // start from the place "0"
    amount_visited = 1;
    vplace[0] = 1;
    now_dis = 0;
    dfs(0);
    printf("%d\n",min_dis);
    return 0;
}