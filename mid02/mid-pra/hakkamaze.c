#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 12510 - Hakka's Maze 
int visited[1010][1010];
char a[1010][1010];
int row,col;
int t_flag;

void dfs(int x,int y)
{
    // up down left right
    int dir_x[5] = {0,-1,1,0,0};
    int dir_y[5] = {0,0,0,-1,1};
    if(!visited[x][y]){
        visited[x][y] = 1;
        if(a[x][y] == 'T')
            t_flag = 1;
        for(int i = 1; i <= 4; i ++){
            int new_x = x + dir_x[i];
            int new_y = y + dir_y[i];
            // if walk to the boundry , go to the next for loop
            if(new_x < 0 || new_y < 0 || new_x >= row || new_y >= col )
                continue;
            // if walk to the wall , go to the next for loop
            else if(a[new_x][new_y] == '#')
                continue;
            /*else if(a[new_x][new_y] == 'T'){
                t_flag = 1;
                continue;
            }*/
            else dfs(new_x,new_y);
        }
    }
    else return;
}

int main()
{
    int n; 
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        scanf("%d%d",&row,&col);
        for(int i = 0; i < row; i ++)
            scanf(" %s",a[i]);
        // initialize
        memset(visited,0,sizeof(visited));
        t_flag = 0;

        dfs(0,0);

        // use each 'T' as starting point
        if(t_flag){
            for(int i = 0; i < row; i ++){
                for(int j = 0; j < col; j ++){
                    if(a[i][j] == 'T')
                        dfs(i,j);
                }
            }
        }
        if(visited[row-1][col-1])
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}