#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 12099 - String sorting
int i;
#define MAX 200002

int cmp(const void *a, const void *b) { 
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strcmp(*ia, *ib);
    // return strcmp(*(char **)a, *(char **)b);
}

int main()
{
    char **str;
    str = (char**) malloc( sizeof(char*) * MAX);
    for(i = 0; i < MAX; i ++){
        str[i] = (char*) malloc(sizeof(char) * 102);
    }

    char temp[102];
    int j = 0;
    while( scanf(" %s",temp) != EOF ){
        strcpy(str[j ++],temp);
    }
    //printf("%d\n",j);
    qsort(str,j,sizeof(char*),cmp);
    int k;
    for(k = 0; k < j; k ++){
        if(str[k][0] != '\0')
            printf("%s\n",str[k]);
    }
    //printf("\n");
    /*
    qsort(str,i,sizeof(char*),cmp);
    for(int k = 0; k < i; k ++){
        if(str[k][0] != '\0')
            printf("%s",str[k]);
    }*/
    //printf("\n");
    return 0;
}

