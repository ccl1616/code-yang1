#include <stdio.h>
//12411-bignumber multiplication
int main()
{
    int num[4] = {0};
    int ans[8] = {0};
    char input[16];
    //input
    for(int i = 0;i < 16; i ++) scanf("%c",&input[i]);

    //convert input into base 10000
    for(int d = 0; d < 16; d ++){
        int a = (15 - d) / 4;
        num[a] *= 10;
        num[a] += input[d] - '0';
    }
    //do multiplication
    for(int up = 0; up < 4; up ++){
        for(int down = 0; down < 4; down ++){
            ans[up + down] += num[up] * num[down];
        }
    }

    //deal with carry
    for(int d = 0; d < 7; d ++){
        ans[d+1] += ans[d] / 10000;
        ans[d] %= 10000;
    }
    //print ans
    printf("%4d",ans[7]);
    for(int d = 6; d >= 0; d --) printf("%04d",ans[d]);
    printf("\n");

    return 0;
}