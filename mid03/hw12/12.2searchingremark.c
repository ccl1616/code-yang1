#include <string.h>
#include <stdio.h>
char s[1000],tar[25]; 
// 12507 - Searching Remark
int tester( char now[1000] )
{
    int len = strlen(tar);
    if( len != strlen(now) )
        return 0;
    for(int i = 0; i < len; i ++){
        if(now[i] + 32 == tar[i] || now[i] == tar[i] || now[i] - 32 == tar[i])
            continue;
        else return 0;
    }
    return 1;
}

int main () {
    char d[14] = {' ', '\n', '-', '/', ':', '(', ')', '[', ']', ',', '.'};
    char *r; // temp word
    int ans = 0;
    scanf("%s",tar);

    while(fgets(s, 1000, stdin) != NULL){
        r = strtok(s, d);  
        while( r != NULL ){
            if( tester(r) )
                ans ++;
            r = strtok(NULL, d);      
        }
    }
    printf("%d\n",ans);
    return(0);
}