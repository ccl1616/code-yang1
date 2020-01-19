#include<string.h>
#include<stdio.h>
#include <stdlib.h>
// string
#define maxtest 200005

int cmp(const void *a,const void *b)
{
    char **c = (char **)a;
    char **d = (char **)b;
    return strcmp(*c,*d);
}
int main()
{
    char **str;
    str = (char**) malloc(sizeof(char*)*maxtest);
    for(int i = 0; i < maxtest; i ++)
        str[i] = (char*) malloc(sizeof(char)*101);
    char temp[101];
    int j = 0;
    while(scanf("%s",temp) != EOF){
        strcpy(str[j++],temp);
    }
    qsort(str,j,sizeof(char*),cmp);
    for(int i = 0; i < j; i ++){
        if(str[i][0] != '\0'){
            printf("%s\n",str[i]);
        }
    }
    return 0;
}