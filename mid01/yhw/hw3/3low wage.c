#include <stdio.h>
int main(void)
{
    int X;
    int H1,M1,S1,H2,M2,S2;
    int time1,time2,workingtime;
    scanf("%d",&X);
    scanf("%d:%d:%d ~ %d:%d:%d",&H1,&M1,&S1,&H2,&M2,&S2);
    time1=3600*H1+60*M1+S1;
    time2=3600*H2+60*M2+S2;
    workingtime=time2-time1;
    int wh,wm,ws;
    wh=workingtime/3600;
    wm=workingtime%3600/60;
    ws=workingtime%3600%60;
    printf("Working Time: %d Hour(s) %d Minute(s) %d Second(s)\n",wh,wm,ws);
    printf("Daily Wage: %d TWD\n",X*wh);
    return 0;
}