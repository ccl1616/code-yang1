#include <stdio.h>
#include <string.h>
//fullhouse

int t; 
char str[5][3];
int cards[14]; 
int main(void)
{
    scanf("%d", &t);

    while(t--){
        scanf("%s%s%s%s%s",str[0],str[1],str[2],str[3],str[4]);
        for(int i = 1; i <= 13; i ++) cards[i] = 0;
        int count2 = 0, count3 = 0; 

        for(int i = 0; i < 5; i ++){
            if(str[i][0] == 'A') cards[1] ++;
            else if(str[i][0] == '1') cards[10] ++;
            else if(str[i][0] == 'J') cards[11] ++;
            else if(str[i][0] == 'Q') cards[12] ++;
            else if(str[i][0] == 'K') cards[13] ++;
            else cards[str[i][0]-'0'] ++;
        }
        for(int i = 1; i <= 13; i ++){
            if(cards[i] == 2) count2 = 1;
            else if(cards[i] == 3) count3 = 1;
        }

        if(count2 == 1 && count3 ==1) printf("YES\n");
        else  printf("NO\n");

    }
    return 0;
}