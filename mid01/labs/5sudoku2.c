#include<stdio.h>
#include<ctype.h>

char b[82];
int a[9][9];

int main(void){
    int valid = 1,qs = 0; //valid=1 invalid=0 q=1 s=0
    char c;
    int z = 1;
    for(int i = 0; i <= 181; i ++){ 
        c = getchar();
        if(isdigit(c) || c =='x'){
            if(c == 'x') {
                b[z] = 0;
                qs = 1; //it is a question
            }
            else b[z] = c - 48;
            z ++;
        }
    }

    z = 1;
    for(int i = 0; i < 9; i ++){
        for(int j = 0; j < 9; j ++){
            a[i][j] = b[z];
            z ++;
        }
    }

    for(int k = 0; k < 9; k ++){
        //check row
        for(int m = 0; m < 9; m ++){ 
            int c[10] = {0,0,0,0,0,0,0,0,0,0};
            for(int n = 0; n < 9; n ++){
                if(a[m][n] != 0){
                    if(c[a[m][n]] != 0) valid = 0;
                    c[a[m][n]] = 1;
                }
            }
        }

        //check column
        for(int n = 0; n < 9; n ++){
            int c[10] = {0,0,0,0,0,0,0,0,0,0};
            for(int m = 0; m < 9; m ++){
                if(a[m][n] != 0){
                    if(c[a[m][n]] != 0) valid = 0;
                    c[a[m][n]] = 1;
                }
            }
        }
    }

    //check blocks
    for(int n = 0; n <= 6; n+=3){
        for(int m = 0; m <= 6; m += 3 ){
            int c[10] = {0,0,0,0,0,0,0,0,0,0};
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(a[i+n][j+m] != 0){
                        if(c[a[i+n][j+m]] != 0) valid = 0;
                        c[a[i+n][j+m]] = 1;
                    }
                }
            }
        }
    }
    
    if(qs) printf("question, ");
    else printf("solution, ");

    if(valid) printf("valid\n");
    else printf("invalid\n");
    
    return 0;
}
