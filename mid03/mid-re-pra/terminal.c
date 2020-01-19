#include <stdio.h>
#include <string.h>
#define MAX 100005
char input[MAX],output[MAX],temp[MAX];
// terminal
int main()
{
    fgets(input,sizeof(input),stdin);
    int pos = 0;
    int w = 80, h = 24;
    int len = strlen(input);

    for(int i = 0; i < len; i ++){
        if(input[i] == '\n') continue;
        else if(input[i] == '\\'){
            i++;
            if (input[i] == 'n'){
                strcpy(temp,&output[pos]);
                strcpy(&output[pos+1],temp);
                output[pos++] = '\n';
            }
            else if(input[i] == 'b' && pos != 0){
                strcpy(temp,&output[pos--]);
                strcpy(&output[pos],temp);
            }
            else if(input[i] == 'l'){
                if(pos > 0)
                    pos --;
            }
            else if(input[i] == 'r'){
                if(output[pos] != 0)
                    pos ++;
            }
            else if(input[i] == 's'){
                w = 0;
                h = 0;
                i+=3;
                while(input[i] != ' '){
                    w = 10*w + (input[i] - '0');
                    i ++;
                }
                i ++;

                while(input[i] != ']'){
                    h = 10*h + (input[i] - '0');
                    i ++;
                }
            }
        }
        else {
            if(output[pos] == 0){
            output[pos++] = input[i];
            }
            else {
                strcpy(temp,&output[pos]);
                strcpy(&output[pos+1],temp);
                output[pos++] = input[i];
            }
        }
    }

    int k = 0, end = 0;
    //printf("%s", output);
    for(int i = 0; ; i++){

        for(int j = 0; j < w; j ++){
            if(output[k+1] == 0){
                end = 1;
                printf("%c",output[k]);
                break;
            }
            else if(output[k] == '\n')
                j = -1;
            printf("%c",output[k]);
            k ++;
        }
        if(end) break;
        if(output[k] != '\n') puts("");

    }
    return 0;
}