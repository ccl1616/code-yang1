#include <stdio.h>
#include <string.h>
// 12519 - The Secrecy between Bob and Alice
int N;
char str[5010][5010];
char P[5010];
int map[27][3];
int f[5000];
int temp = 0;
int len;

int check(char compare_str[])
{
    if( strlen(compare_str) != len)
        return 0;
    int flag = 1;
    for(int i = 0; i < 26; i++)
        map[i][1] = 0; 
    for(int i = 0; i < len; i ++)
        map[ compare_str[i]-97 ][1] ++; 

    for(int i = 0; i < len; i ++){
        if( map[ P[i]-97 ][0] != map[ compare_str[i]-97 ][1] ){
            return 0;
        }
    }
    return flag; 
}

int main(void)
{
    scanf("%d %s",&N,P);
    len = strlen(P);
    for(int i = 0; i < len; i++)
        map[ P[i]-97 ][0] ++; 

    for(int i=0;i<N;i++){
        char input[5010];
        int flag = 0;
        scanf("%s",input);
        if(check(input)==0)
            continue;
        int j;
        for(j=0;j<temp;j++){
            if(strcmp(str[j],input)==0){
                flag = 1;
                break;
            }
        }
        if(flag){
            f[j]++;
        }
        else{
            strcpy(str[temp],input);
            f[temp] = 1;
            temp++;
        }
    }

    for(int i=0;i<temp;i++){
        for(int j=0;j<temp-i-1;j++){
            int flag = 0;
            if(f[j]<f[j+1])
                flag = 1;
            else if(f[j]>f[j+1])
                flag = 0;
            else{
                if(strcmp(str[j],str[j+1])>0)
                    flag = 1;
                else{
                    flag = 0;
                }
            }
            if(flag){
                // do the swaping
                char change[5010]; 
                strcpy(change,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],change);

                int change_int=f[j];
                f[j]=f[j+1];
                f[j+1]=change_int;
            }
        }
    }

    printf("%d\n",temp);
    for(int i=0;i<temp;i++){
        printf("%s %d\n",str[i],f[i]);
    }
}

