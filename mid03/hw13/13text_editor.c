#include <stdio.h>
#include <string.h>
// 11269 - Text Editor 
#define MAX_SIZE 505

char save[MAX_SIZE];
char input[MAX_SIZE];

int main()
{

    fgets(input, MAX_SIZE, stdin); 
    int i = 0;
    int pos = 0;
    //while(input[i]){
    for(i = 0; i < MAX_SIZE;){
        if(input[i] == '/'){
            if(input[i+1] == 'b'){
                save[pos-1] = '\0';
                if(pos - 1 >= 0) pos -= 1;
                else pos = 0;
                i += 10;
                continue;
            }
            else if(input[i+1] == 'l'){
                if(pos - 1 >= 0) pos -= 1;
                else pos = 0;
                i += 5;
                continue;
            }
            else if(input[i+1] == 'r'){
                if(pos + 1 < MAX_SIZE) pos += 1;
                else pos = MAX_SIZE;
                i += 6;
                continue;
            }
            else if(input[i+1] == 'n'){
                save[pos] = '*';
                if(pos + 1 < MAX_SIZE) pos += 1;
                else pos = MAX_SIZE;
                i += 8;
                continue;
            }
        }
        else {
            save[pos] = input[i];
            //printf("%d %c\n",pos,save[pos]);
            pos ++;
        }
        i ++;
    }
    for(i = 0; i < MAX_SIZE; i ++){
        if(save[i] == '*')
            putchar('\n');
        else if(save[i] != '\0')
            printf("%c",save[i]);
    }
    //printf("%d\n",pos);
    return 0;
}