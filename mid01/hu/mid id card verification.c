#include<stdio.h>
#include<string.h>
//id card verification
char str[11];
int a[11];

int main(){
    
    scanf("%s",str);
    char c;
    c = str[0];
    int mapping[26] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
    a[0] = mapping[c - 'A'] / 10;
    a[1] = mapping[c - 'A'] % 10;
    
    for(int i = 1; i <= 9; i ++){
        a[i+1] = str[i] - '0';
    }
    
    int weight[11] = {1,9,8,7,6,5,4,3,2,1,1};
    int ans = 0;
    for(int i = 0; i <= 11; i ++){
        ans += a[i] * weight[i];
    }
    //printf("%d\n",ans);
    if(ans%10 == 0) printf("Real\n");
    else printf("Fake\n");

    return 0;
}