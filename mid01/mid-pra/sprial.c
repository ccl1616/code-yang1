#include <stdio.h>
#include <stdlib.h>
//spiral

char ans[5000][5000];
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

int main(void)
{
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);

        //全部填空格
        for(int i = 0; i < n; i ++){
			for(int j = 0; j < n; j ++){
				ans[i][j] = ' ';
			}
		}

        //製造＃
        int x = 0, y = -1; //從(0.-1)出發
        int j = 0; //方向指標
        for( int i = n ; i >= 1 ; i -- ){
            for( int k = 1 ; k <= i ; k ++ ){
                x += dir[j][0];
                y += dir[j][1];
                ans[x][y] = '#';
                //printf("%d %d\n", x,y);
                //printf("j = %d\n",j);
            }
            j = (j + 1) % 4;
        }

        //print out
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < n ; j ++){
                //if(ans[i][j] != '#') ans[i][j] = ' '; //多一個if不好 所以要一開始全部填空格
                printf("%c",ans[i][j]);
            }
            printf("\n");
        }

    }
    return 0;
}

