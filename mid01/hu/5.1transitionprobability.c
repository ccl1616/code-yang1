#include<stdio.h>
//11131 - Transition probability   
float p[2][2];
float val[1][2];

int main()
{
    float n;
    float target_val;
    float temp1,temp2;
    scanf("%f",&n);
    for(int i = 0; i < n; i ++){
        scanf("%f%f%f%f%f",&p[0][0],&p[0][1],&p[1][0],&p[1][1],&target_val);
        //printf("%lf\n",target_val);
        val[0][0] = 1;
        val[0][1] = 0;
        int count = 0;
        while(val[0][0] >= target_val){
            count ++;
            temp1 = val[0][0]*p[0][0] + val[0][1]*p[1][0];
            temp2 = val[0][0]*p[0][1] + val[0][1]*p[1][1];
            val[0][0] = temp1;
            val[0][1] = temp2;
            //printf("%f %f\n",val[0][0],val[0][1]);
        }

        printf("%d\n",count);
    }
    return 0;
}