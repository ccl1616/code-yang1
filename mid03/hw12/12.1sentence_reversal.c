#include <stdio.h>
#include <string.h>
//11275 - Sentence Reversal
void reverse(int pos,char s[505])
{
    for(int i = pos; i < 505; i ++){
        if(s[i] == '\n'){
            for(int j = pos; j < i; j ++)
                printf("%c",s[j]);
            putchar(' ');
            return;
        }
        else if(s[i] == ' '){
            reverse(i+1,s);
            for(int j = pos; j < i; j ++)
                printf("%c",s[j]);
            if(pos != 0) putchar(' ');
            //break;
            return;
        }
    }
}


int main(void)
{
    char s[505];
    while(fgets(s,505,stdin)!= NULL){
        reverse(0,s);
        printf("\n");
        memset(s,0,sizeof(s));
    }
    return 0;    
}