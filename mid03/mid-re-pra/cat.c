#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// cat
typedef struct cats{
    char name[50];
    int job;
    int age;
}cat;

cat ar[10002];
char jobs[9] = "enkwamdl";
// a = 4


int cmp(const void *c, const void *d)
{
    cat a = *(cat *)c;
    cat b = *(cat *)d;

    // bigger pro, put to the back
    if(a.job > b.job) return 1; 
    else if(a.job < b.job) return -1;

    // same pro
    else if(a.job == b.job){
        // if apprentices, put older to the back

        if(a.age == b.age)
            return strcmp(a.name, b.name);
        else if(a.age > b.age){
            if(a.job == 4) return 1;
            else return -1;
        }
        else if(a.age < b.age){
            if(a.job == 4) return -1;
            else return 1;
        }
            
        /*
        if(a.pro == 4){
            // older to the back
            if(a.age > b.age) return 1;
            else if(a.age == b.age) return strcmp(a.name, b.name); 
            else return -1;
        }
        // else put young to the back
        else{
            // young to the back
            if(a.age < b.age) return 1;
            else if(a.age == b.age) return strcmp(a.name, b.name);
            else return -1;
        }*/
    }
    return -1;
}

int main()
{
    int catnum, foodnum;
    //char temp[50];
    while(scanf("%d%d",&catnum,&foodnum) != EOF){

        for(int i = 0; i < catnum; i ++){
            char temp[50] = {0};
            scanf("%s %s %d",ar[i].name,temp,&ar[i].age);
            for(int j = 0; j < 8; j ++){
                if(temp[0] == jobs[j]){
                    ar[i].job = j;
                    break;
                }
            }
        }
        qsort(ar,catnum,sizeof(cat),cmp);
        for(int i = 0 ; i < catnum && i < foodnum ; i ++)
            printf("%s\n",ar[i].name);

    }
    return 0;
}
