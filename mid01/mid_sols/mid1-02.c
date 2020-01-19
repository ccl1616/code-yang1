#include<stdio.h>
//12446 - Bacteria Widespread   
char a[100][100];
char c[100][100];
int b[100][100];

int main(void)
{
    int r,c,t;
    scanf("%d%d%d",&r,&c,&t);
    for(int i = 0; i < r; i ++){
        for(int j = 0; j < c; j ++){
            scanf(" %c",&a[i][j]);
        }
    }

    int x,y;
    int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
    while(t --){
        for(int i = 1; i <= r - 2; i ++){
            for(int j = 1; j <= c - 2; j ++){
                b[i][j] = 0;
            }
        }
        for(int i = 1; i <= r - 2; i ++){
            for(int j = 1; j <= c - 2; j ++){
                int d = 0;
                if(a[i][j] == 'F' && b[i][j] == 0){
                    while(d <= 3){
                        x = i + dir[d][0];
                        y = j + dir[d][1];
                        if(a[x][y] != '#' && b[x][y] != 1 && a[x][y] != 'F'){
                            a[x][y] = 'F';
                            b[x][y] = 1;
                        }
                        d ++;
                    }
                }
            }
        }
    }
    for(int i = 0; i < r; i ++){
        for(int j = 0; j < c; j ++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}

