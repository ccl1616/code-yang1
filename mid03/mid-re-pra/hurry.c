// hurry
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a,b) (a>b ?b :a)
int u[3003],val[3003];
int testcase,k,p,ans;
// u == 1 == occupied
// index for the "u"
int cleft(int pos)
{
    int temp = 0;
    if(pos-1 == 0) return 0;
    pos --;
    for(int i = pos; i >= 1; i--){
        if(u[i] == 1)
            break;
        else temp ++;
    }
    return temp;
}
int cright(int pos)
{
    int temp = 0;
    if(pos == p) return 0;
    pos ++;
    for(int i = pos; i <= p; i ++){
        if(u[i] == 1)
            break;
        else temp ++;
    }
    return temp;
}

int func(int p,int k)
{
    int temp,max;
    while(k -- ){
        // 先把每一個位置的值算出來 每次算之前都要清空
        max = 0;
        memset(val,0,sizeof(val));
        for(int i = 1; i <= p; i ++){
            if(u[i] != 1){
                val[i] = min(cright(i),cleft(i)); 
                if(val[i] > max)
                    max = val[i];
            }
        }
        for(int i = 1; i <= p; i ++){
            if(val[i] == max && u[i] != 1){
                temp = i;
                u[i] = 1;
                break;
            }
        }
    }
    return temp;
}

int main()
{
    scanf("%d",&testcase);
    while(testcase --){
        memset(u,0,sizeof(u));
        memset(val,0,sizeof(val));
        scanf("%d%d",&p,&k);

        if(k == 1){
            if(p % 2 == 0)
                ans = p/2;
            else ans = p/2 + 1;
        }

        else if(k == p)
            ans = p;

        else {
            if(p % 2 == 0)
                u[p/2] = 1;
            else u[p/2 + 1] = 1;
            ans = func(p,k-1);
        }
        printf("%d\n",ans); 
    }
    return 0;
}