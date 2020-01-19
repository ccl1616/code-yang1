#include <stdio.h>
#include <string.h>
// 12078 - Hurry!
#define maxsize 3002
#define min(a,b) ( a > b ? b : a )
int array[maxsize]; 
int ans[maxsize];
int n,k;

int countleft(int pos)
{
    int temp;
    temp = 0;
    if(pos - 1 == 0) 
        return 0;   
    pos -= 1;
    for(int i = pos ; i >= 1; i --){
        if(ans[i] >= 1)
            break;
        else temp ++;
    }
    return temp;
}

int countright(int pos)
{
    int temp;
    temp = 0;
    if(pos + 1 > n) 
        return 0;
    pos += 1;
    for(int i = pos; i <= n; i ++){
        if(ans[i] >= 1)
            break;
        else temp ++;
    }
    return temp;
}

int func(int n,int k)
{
    int temp;
    while(k --){
        memset(array,0,sizeof(array));
        int max = 0;
        for(int i = 1; i <= n; i ++){
            if(ans[i] != 1){
                array[i] = min(countleft(i),countright(i));
                if(array[i] > max)
                    max = array[i];
            }
        }
        for(int i = 1; i <= n; i ++){
            //printf("%d ",array[i]);
            if(array[i] == max && ans[i] != 1){
                ans[i] = 1;
                temp = i;
                break;
            }
        }
    }
    return temp;
}

int main()
{
    int testcase,output,count,max;
    scanf("%d",&testcase);
    while(testcase -- ){
        memset(array,0,sizeof(array));
        memset(ans,0,sizeof(ans));

        scanf("%d%d",&n,&k);
        if(k == 1){
            if(n%2 == 0)    output = n/2;
            else output = n/2 + 1;
        }
        else if(k == n)
            output = n;
        else{
            if(n%2 == 0)    ans[n/2] = 1;
            else ans[n/2+1] = 1;
            output = func(n,k-1);
        }
        printf("%d\n",output);
    }
    return 0;
}