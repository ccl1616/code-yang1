#include<stdio.h>
#include<string.h>
//12460 - Little Brick's Choice - lab07 

char in[16+1]={'\0'};
char _in[16+1]={'\0'}; //sorted
//int inLen;

int npasswd;
char passwd[16+1];

void perm(int pos, int start, int end)
{
    int i;

    //basis step
    if(pos>=4)
    {
        npasswd++;
        passwd[pos]='\0';
        if(npasswd==1) printf("%s",passwd);
        else printf(", %s",passwd);
    }

    //recursive step
    for(i=start;i<=end;i++)
    {
        passwd[pos]=_in[i];
        perm(pos+1,i+1,end);
    }
}

int main(void)
{
    char map[53] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',\
                    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    scanf("%s",in);
    int num = strlen(in);
    int min;
    for(int i = 0; i < num; i ++){
        for(int j = 0; j < 52; j ++){
            if(in[i] == map[j]){
                if(i == 0) min = j;
                else if(j < min) min = j;
            }
        }
    }
    _in[0] = map[min];
    int x = 1;
    for(int k = min + 1; k < 52; k ++){
        for(int i = 0; i < num; i ++){
            if(in[i] == map[k]){
                _in[x] = in[i];
                x ++;
            }
        }
    }
    //for(int i = 0; i < num; i ++) printf("%c ",_in[i]);
    perm(0,0,num-1);
    printf("\n");
    return 0;
}