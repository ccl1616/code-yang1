#include <stdio.h>
#include <stdlib.h>
//arranging a sequence

int t[200005],a[200005]; 
int main(void)
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int k = m ; k >= 1 ; k --){
        scanf("%d",&a[k]);
    }
    
    for(int i = 1 ; i <= m ; i ++){
        if(t[a[i]] == 0){ //********
            printf("%d\n",a[i]);
            t[a[i]] = 1;
        }
    }
    
    for(int i = 1 ; i <= n ; i ++){
        if(t[i] == 0) printf("%d\n",i);
    }

    return 0;
}