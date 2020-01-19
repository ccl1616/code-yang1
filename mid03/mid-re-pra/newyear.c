#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// new year
int a[10005];

int main()
{
    int bob;
    scanf("%d",&bob);
    for(int i = 1; i <= bob; i ++)
        scanf("%d",&a[i]);
    int ans = 0;
    
    int i = a[bob];
    while(i > 0){
        ans ++;
        i = a[i];
    }
    int unclesparent = a[a[bob]];
    for(int i = 1; i <= bob; i ++){
        if(a[i] == unclesparent)
            ans ++;
    }

    //printf("%d\n",i);
    printf("%d\n",ans-1);
    return 0;
}