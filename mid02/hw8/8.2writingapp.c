#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//12458 - Writing APP
char str[1000];
int map[1000][1000];

int checkpal(int l, int r)
{
    int deleteleft = 0;
    int deleteright = 0;

    //basis
    if(l >= r) {
        map[l][r] = 0;
        return map[l][r];
    }
    //recursive step1
    if(str[l] == str[r]){
        map[l][r] = checkpal(l+1, r-1);
        return map[l][r];
    }
    //recursive step2
    else{
        if(map[l][r] == __INT_MAX__){
            deleteleft = checkpal(l+1,r);
            deleteright = checkpal(l,r-1);
            if(deleteleft > deleteright) map[l][r] = (deleteright+1);
            else map[l][r] = (deleteleft+1);

            return map[l][r];
        }
        else return map[l][r];
    }
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    getchar();
    for(int i = 0; i < n; i ++) scanf("%c",&str[i]);
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            map[i][j] = __INT_MAX__;
        }
    }
    int ans = checkpal(0 ,n-1);
    //printf("%d\n",ans);
    if(ans <= k) printf("Yes\n");
    else printf("No\n");

    return 0;
}