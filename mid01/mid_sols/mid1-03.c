#include<stdio.h>
//12447-How Much Bateria

int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    int a[n];
    int b[q][32];
    for(int i = 0; i < n; i ++){
        scanf("%d",&a[i]);
    }
    
    for(int j = 0; j < 32; j ++) b[0][j] = 0;
    
    for(int i = 0; i < n; i ++){
        if (i == 0) b[i][a[i]] = 1;
        else {
            //先等於前一列
            for(int j = 0; j < 32; j ++) b[i][j] = b[i - 1][j];
            //再將該蟲+1
            b[i][a[i]] +=  1;
        }
    }
    
    int left,right;
    for(int i = 0; i < q; i ++){
        scanf("%d%d",&left,&right);
        int ans = 0;
        if(left == 0) {
            for(int j = 0; j < 32; j ++)
                if(b[right][j] != 0) ans ++;
        }
        else {
            for(int j = 0; j < 32; j ++)
            if(b[right][j] - b[left - 1][j] != 0) ans ++;
        }
        printf("%d\n",ans);
    }
    return 0;
}