#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//12519 - The Secrecy between Bob and Alice
int map[27][3];
char mainstr[5010];
char input[5010][5010];
int ans[5010]; // if same pattern :1 , it not : 0
int id[5010]; // 
int n; // n = number of the compares
int count;
int len;

void swap_int(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int check(char compare_str[])
{
    int flag = 1;
    for(int i = 0; i < 26; i++)
        map[i][1] = 0; 
    for(int i = 0; i < len; i ++)
        map[ compare_str[i]-97 ][1] ++; 

    for(int i = 0; i < len; i ++){
        if( map[ mainstr[i]-97 ][0] != map[ compare_str[i]-97 ][1] ){
            flag = 0;
            break;
        }
    }
    return flag; 
}

//deal with the frequency. 
//pick out the same string and : 1.clear the answer to 1, 2.add 1 to the target string
void frequency_dealer(int i)
{
    for(int j = 0; j < n; j ++){
        if( j != i && strcmp(input[i],input[j]) == 0){
            ans[j] = 0;
            ans[i] ++;
        }
    }
    count ++;
}

int main()
{
    scanf("%d %s",&n,mainstr);
    len = strlen(mainstr);

    //save the mainstr into first col
    for(int i = 0; i < len; i++)
        map[ mainstr[i]-97 ][0] ++; 

    for(int i = 0; i < n; i ++){
        id[i] = i;
        scanf(" %s",input[i]);

        // same words or same len
        if(strcmp(input[i],mainstr) == 0)
            ans[i] = 1;
        else if(len == strlen(input[i]))
            ans[i] = check(input[i]);
        else ans[i] = 0;
    }

    //if with the same pattern, use the frequency_dealer
    for(int i = 0; i < n; i ++){
        if(ans[i] == 1){
            frequency_dealer(i);
        }
    }
    //bubble sort by the value of ans; put the smaller ans to back
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n-1-i; j ++){
            if( ans[j] < ans[j+1]){
                swap_int(&ans[j],&ans[j+1]);
                swap_int(&id[j],&id[j+1]);
            }
    		else if( ans[j] == ans[j+1] && strcmp(input[j],input[j+1]) > 0 )
                swap_int(&id[j],&id[j+1]);
        }
    }

    printf("%d\n",count);
    
    for(int i = 0; i < count; i ++){
        //if(ans[i] != 0)
            printf("%s %d\n",input[id[i]],ans[i]);
    }
    return 0;
}