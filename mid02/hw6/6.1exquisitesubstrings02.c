#include <stdio.h>
#include <string.h>
//11621 - pE - Exquisite Substrings   
//ta version wrote by myself
int main()
{
    char str[2000];
    while(scanf("%s", str) != EOF){
       int len = strlen(str);
       int ans = 0;

       //one center
       int center = 1;
       for(int i = center ; i < len - 1 ; i ++){ 
            for(int j = 1; i + j < len; j ++){ 
                if(i - j >= 0 && i + j < len){ 
                    if(str[i - j] == str[i + j]) ans ++;
                    else break;
                }
                else break;
            }
       }
       
       //2 center 
       int leftcenter = 0; // rightcenter == 1
       for(int i = leftcenter ; i + 1 <= len - 1 ; i ++){ 
            if(str[i] == str[i + 1]) {
                ans ++;
                if(i - 1 >= 0 && i + 2 < len){
                    for(int j = 1; i + 1 + j < len; j ++){ 
                        if(i - j >= 0 && i + 1 + j < len){ 
                            if(str[i - j] == str[i + 1 + j]) ans ++;
                            else break;
                        }
                        else break;
                    }
                }
            }
       }
       
       printf("%d\n",ans);
    }
    return 0;
}