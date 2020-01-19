#include<stdio.h>
#include <stdlib.h>
#define max(a,b) (a > b ?a :b)
//10845 - Light Reflection
int h,w; 
int dir;
int check(int x,int y,int dir)
{
    int ans;
    // corner
    if( x == 1 && y == 1 )
        ans = 5;
    else if( x == 1 && y == w )
        ans = 5;
    else if( x == h && y == 1 )
        ans = 5;
    else if( x == h && y == w )
        ans = 5;

    // ceilling
    else if( x == 1 ){
        if( dir == 1 ) ans = 2;
        else if( dir == 4) ans = 3;
    }
    // floor
    else if( x == h ){
        if( dir == 2 ) ans = 1;
        else if( dir == 3 ) ans = 4;
    }
    //right wall
    else if( y == w ){
        if( dir == 2 ) ans = 3;
        else if( dir == 1 ) ans = 4;
    }
    // left wall
    else if( y == 1 ){
        if( dir == 3 ) ans = 2;
        else if( dir == 4 ) ans = 1;
    }
    // keep moving
    else ans = 0;

    return ans;
}

int** build_array(int h, int w)
{
    int **a;
    int *b;
    
    b = (int*) malloc( sizeof(int)*(h+1)*(w+1) );
    a = (int**) malloc( sizeof(int*)*(h+1) );
    for(int i = 0; i < (h+1); i++)
        a[i] = b + i*(w+1);

    return a;
}

void delete_array(int **a)
{
    free(a[0]);
    free(a);
}

int main()
{
    // height and width
    scanf("%d%d",&h,&w);
    int **array = build_array(h,w);
    // starting pos
    int x,y; 
    scanf("%d%d",&x,&y);
    //k-th
    int k; 
    scanf("%d",&k);
    k = k - 1; // if not corner, move k-1 times

    int move_x[5] = {0,-1,1,1,-1};
    int move_y[5] = {0,1,1,-1,-1};
    int max;
    max = max(h,w);
    dir = 1;
    
    for(int i = 0; i < k; i ++){
        //printf("dir = %d\n",dir);
        if(dir == 5)
            break;
        for(int j = 0; j < max; j ++){
            x += move_x[dir];
            y += move_y[dir];
            //printf("%d %d\n",x,y);
            if(check(x,y,dir) != 0) {
                dir = check(x,y,dir);
                break;
            }
        }
    }

    printf("(%d,%d)",x,y);
    delete_array(array);
    return 0;
}