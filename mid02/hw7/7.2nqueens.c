#include<stdio.h>
//11222 - N queens
int valid(int row, int col);
int place(int row, int size);
int q[10];
int ans;

int main()
{
    int n;
    scanf("%d",&n);
    place(0 , n);
    printf("%d\n",ans);
    return 0;
}

int place(int row, int size)
{
    int n = size;
    if(row == size) ans ++;
    for(int j = 0; j < n; j ++){
        if(valid(row,j)){
            q[row] = j;
            place(row + 1, n);
        }
    }
    return ans;
}

int valid(int row, int col)
{
    int i;
    for(i = 0; i <= row - 1; i++){
        if(q[i] == col || q[i] == col - row + i || q[i] == col + row - i)
            return 0;
    }
    return 1;
}

