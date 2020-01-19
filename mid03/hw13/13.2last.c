#include <stdio.h>
#include <string.h>
#include <ctype.h>
// 11269 - Text Editor 
#define MAX_SIZE 505

char content[MAX_SIZE];
char input[MAX_SIZE];
char temp[MAX_SIZE];

int main()
{

    fgets(input, MAX_SIZE, stdin); 
    int i = 0;
    int pos = 0;
    for(int i = 0; i < MAX_SIZE; i ++){
        if(input[i] == '/'){
            if(input[i+1] == 'b'){
                if(pos != 0){
                    // 把pos開始之後的字串抓出來 直接蓋在pos-1之上 這樣pos-1的地方（要刪掉的字）就會被蓋掉
                    strcpy(temp,&content[pos]);
                    pos --;
                    strcpy(&content[pos],temp);
                }
                i += 9;
                continue;
            }
            else if(input[i+1] == 'l'){
                if(pos != 0)
                    pos --;
                i += 4;
                continue;
            }
            else if(input[i+1] == 'r'){
                if(content[pos] != 0) // if there's no letters in it, you can't go
                    pos ++;
                i += 5;
                continue;
            }
            else if(input[i+1] == 'n'){
                i += 7;
                strcpy(temp,&content[pos]);
                strcpy(&content[pos+1],temp);
                content[pos++]='\n';
                continue;
            }
        }
        else if(isalpha(input[i]) || input[i]==' '){
            // move the \0 to the back of new letters
            strcpy(temp,&content[pos]);
            strcpy(&content[pos+1],temp);
            content[pos++]=input[i];
        }
    }
    printf("%s",content);
    return 0;
}