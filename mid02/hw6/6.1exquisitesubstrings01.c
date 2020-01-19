#include <stdio.h>
#include <string.h>
//11621 - pE - Exquisite Substrings
//my version 1TLE
int main()
{
    char str[2000];
    while(scanf("%s", str) != EOF){
       int len = strlen(str);
       //printf("%d\n",len);
       int count = 0, ans = 0;
       for(int i = 0; i < len - 1; i ++){
           for (int j = i + 1; j < len; j ++){
                for (int k = 0; k < j; k ++){
                    if((i + k) < (j - k)){
                        if(str[i + k] != str[j - k]) {
                            count = 0;
                            break;
                        }
                        else if(str[i + k] == str[j - k]) count = 1;
                    }
                    if(count == 0) break;
               }
               //printf("%d\n",count);
               ans += count;
           }
       }
       printf("%d\n",ans);
    }
    return 0;
}
