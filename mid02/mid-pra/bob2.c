#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//12519 - The Secrecy between Bob and Alice
int map[27][3];
char mainstr[5000];
char same[5000][5000];
int same_num[5000]; //if same pattern :1 , it not : 0
int same_index;
int len;
int n; //n = number of the compares

void saveit(char str[]);
void swap_int(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void swap_str(char (*a)[5000], char (*b)[5000])
{
    char temp[5000];
    strcpy(temp,(*a));
    strcpy( (*a), (*b));
    strcpy( (*b), temp);
}

void check(char compare_str[])
{
    
    for(int i = 0; i < same_index; i ++){
        if( strcmp(compare_str,same[i]) == 0){
            same_num[i] ++;
            return;
        }
    }
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
    // if same pattern, save it
    if(flag == 1)   
        saveit(compare_str);
}

void saveit(char str[])
{
    same_num[same_index] ++;
    strcpy(same[same_index],str);
    same_index ++;
}

int main()
{
    scanf("%d %s",&n,mainstr);
    len = strlen(mainstr);
    //save the mainstr into first col
    for(int i = 0; i < len ; i++)
        map[ (int)mainstr[i]-97 ][0] ++; 

    for(int i = 0; i < n; i ++){
        char temp[5000];
        scanf(" %s",temp);

        // if same strlen, check it's mainstr or not, else check it
        // else scan next
        if(len == strlen(temp)){

            if( strcmp(mainstr,temp) == 0 )
                saveit(temp);
            else
                check(temp);
        }
    }

    for(int i = 0; i < same_index; i ++){
        for(int j = 0; j < same_index-1-i; j ++){
            if(same_num[j] < same_num[j+1]){
                swap_int(&same_num[j],&same_num[j+1]);
                swap_str(&same[j],&same[j+1]);
            }
        }
    }
    for(int i = 0; i < same_index; i ++){
        for(int j = 0; j < same_index-1-i; j ++){
            if(same_num[j] == same_num[j+1] && strcmp(same[j],same[j+1]) > 0 ){
                swap_int(&same_num[j],&same_num[j+1]);
                swap_str(&same[j],&same[j+1]);
            }
        }
    }
    
    printf("%d\n",same_index);
    for(int i = 0; i < same_index; i++)
        printf("%s %d\n",same[i],same_num[i]);
    //printf("\n");
    //printf("%s %d\n",same[4],same_num[4]);
    
    return 0;
}
