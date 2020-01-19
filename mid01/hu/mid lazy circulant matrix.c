#include<stdio.h>
//lazy_circulant matrix   
int a[5];

int main(){
    
    for(int j = 0; j < 5 ; j ++){
        scanf("%d",&a[j]);
    }
    int temp, temp2;
    temp = a[1];
    temp2 = a[2];
    a[1] = a[4];
    a[2] = a[3];
    a[3] = temp2;
    a[4] = temp;

    for(int i = 0; i <= 4; i ++){
            printf("%d ",a[i]);
    }
    printf("\n");
    int t = 4;
    while(t--){
        temp = a[4];
        for(int i = 4; i >= 1; i --){
            a[i] = a[i-1];
        }
        a[0] = temp;
        for(int i = 0; i <= 4; i ++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    
    return 0;
}