#include <string.h>
#include <stdio.h>
int num,boxsize;
int a[15],visited[15];
// distributing
int dfs(int sum, int step)
{
    if(step == num)
        return 1;
    for(int i = 0; i < num; i ++){
        if(visited[i] == 0){
            visited[i] = 1;

            if(sum + a[i] < boxsize){
                if(dfs(sum+a[i],step+1))
                    return 1;
            }
            else if(sum+a[i] == boxsize){
                if(dfs(0,step+1))
                    return 1;
            }
            visited[i] = 0;
        }
    }
    return 0;
}
int main()
{
    int testcase;
    scanf("%d",&testcase);
    while(testcase--){
        int sum = 0;
        scanf("%d",&num);
        for(int i = 0; i < num; i ++){
            scanf("%d",&a[i]);
            sum += a[i];
        }

        int i;
        for(i = num; i > 1; i --){
            if(sum % i == 0){
                boxsize = sum /i;
                memset(visited,0,sizeof(visited));
                if(dfs(0,0))
                    break;
            }
        }
        printf("%d\n",i);
    }
    return 0;
}