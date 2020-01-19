#include <stdio.h>
#include <string.h>
int a[15];
int visited[15];
int num,boxsize; // num : number of reels, boxsize: now boxsize

// sum : now used reel numbers 
// size : size of box now;
int dfs(int sum,int step) 
{
    if(step == num) return 1;

    for(int i = 0; i < num; i ++){
        if(visited[i]) continue;
        visited[i] = 1;
        // if now sum + reel[i] < boxsize
        // dfs next level
        if(sum + a[i] < boxsize){
            if(dfs(sum+a[i],step+1))
                return 1;
        }
        // else if it will be full
        // dfs with new box
        else if(sum + a[i] == boxsize){
            if(dfs(0,step+1))
                return 1;
        }
        visited[i] = 0;
    }
    return 0;
}

int main()
{
    int testcase,allsum = 0;
    scanf("%d",&testcase);

    while(testcase --){
        scanf("%d",&num);
        allsum = 0;
        for(int i = 0; i < num; i ++){
            scanf("%d",&a[i]);
            allsum += a[i];
        }
        
        // i = the number of box
        int i;
        for(i = num; i >= 1; i --){
            if( allsum % i == 0){
                boxsize = allsum / i;
                memset(visited,0,sizeof(visited));
                if(dfs(0,0))
                    break;
            }
        }
        printf("%d\n",i);
    }
    return 0;
}