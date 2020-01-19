#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100000];
    while(scanf("%s", str) != EOF) 
    {
        int i = 0, n;
        while(str[i] != '\0') //順便存入str[i] \0則不讀取 跑到\0為止 
            i++;
            n = i - 1; 
            
            for(int j = 0; j <= n; j ++){ //比較每一個字元
                if(str[j] == str[n-j]) //頭和尾巴
                    ; //?????
                else if(str[j] != str[n-j]){
                    printf("No\n");
                    break;
                }

                if(j==n){
                    printf("Yes\n");
                }
            }
    }

    return 0;
}