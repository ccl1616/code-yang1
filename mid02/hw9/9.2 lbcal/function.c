#include<stdio.h>
#include<string.h>
#include<ctype.h>
//12490 - Little Brick's Calculator 
int solver(int **ptr, int *sum, char *s)
{
    int n = strlen(s);
    int j = -1, i = 0;
    int k;
    while(i < n){
        // read in negative number
        if(isdigit(s[i + 1]) && s[i] == '-'){
            j ++;
            *ptr[j] = s[i + 1] - '0';
            *ptr[j] *= (-1);
            i += 2;
            while(i < n){
                if(isdigit(s[i])) {
                    *ptr[j] = *ptr[j] * 10 - (s[i]-'0');
                    i ++;
                }
                else break;
            }
        }
        // read in positive number
        else if(isdigit(s[i])){
            j ++;
            *ptr[j] = s[i] - '0';
            i ++;
            while(i < n){
                if(isdigit(s[i])) {
                    *ptr[j] = *ptr[j] * 10 + (s[i]-'0');
                    i ++;
                }
                else break;
            }
        }
        
        else i++;
    }
    for(int i = 0; i <= j; i ++)
        *sum += *ptr[i];
    return j+1;
}