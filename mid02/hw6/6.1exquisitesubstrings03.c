#include<stdio.h>
#include<string.h>
//11621 - pE - Exquisite Substrings   
//haung version
char str[2000];
int main()
{
    while(scanf("%s",str) != EOF){
        int len = strlen(str);
        int ans = 0;
        for(int i = 0; i < len; i ++){
            //ans = 0;
            int j = 0;
            while(i - j >= 0){
                if(str[i - j] == str[i + 1 + j]) {
                    ans ++;
                    j ++;
                }
                else break;
            }
            
            j = 1;
            while(i - j >= 0){
                if(str[i - j] == str[i + j]) {
                    ans ++;
                    j ++;
                }
                else break;
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}