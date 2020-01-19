#include <stdio.h>
#include <string.h>
#include <ctype.h>
// 11269 - Text Editor 
#define MAX_SIZE 500

char content[MAX_SIZE];
char input[MAX_SIZE];
int main() 
{
    fgets(input, MAX_SIZE, stdin);
    int cursor = 0;
    char temp[MAX_SIZE]={0};
    for(int i=0;i<MAX_SIZE;i ++){
        if(input[i]=='/'){
            if(input[i+1]=='b'){
                i += 9;
                if(cursor!=0){
                    strcpy(temp,&content[cursor]);
                    cursor--;
                    strcpy(&content[cursor],temp);
                }
            }
            else if(input[i+1]=='n'){
                i += 7;
                strcpy(temp,&content[cursor]);
                strcpy(&content[cursor+1],temp);
                content[cursor++]='\n';
            }
            else if(input[i+1]=='l'){
                i += 4;
                if(cursor!=0)
	                cursor --;
            }
            else if(input[i+1]=='r'){
                i += 5;
                if(content[cursor]!=0)
	                cursor ++;
            }
        }
        else if(isalpha(input[i])||input[i]==' '){
            strcpy(temp,&content[cursor]);
            strcpy(&content[cursor+1],temp);
            content[cursor++]=input[i];
        }
    }
    printf("%s", content);
    return 0;
}