#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 11490 - The Cat Society
typedef struct cats{
    char name[32];
    int age;
    int pro;
}cat;
cat r[10010];

int cmp(const void *c, const void *d)
{
    cat a = *(cat *)c;
    cat b = *(cat *)d;

    // bigger pro, put to the back
    if(a.pro > b.pro) return 1; 
    else if(a.pro < b.pro) return -1;

    // same pro
    else if(a.pro == b.pro){
        // if apprentices, put older to the back

        if(a.age == b.age)
            return strcmp(a.name, b.name);
        else if(a.age > b.age){
            if(a.pro == 4) return 1;
            else return -1;
        }
        else if(a.age < b.age){
            if(a.pro == 4) return -1;
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

char prolist[10] = "enkwamdl";


int main(){
    int n, m,flag;
    while(scanf("%d %d", &n, &m) != EOF){
        
        for(int i = 0; i < n; i ++){
            char tmp[32] = {0};
            scanf("%s %s %d", r[i].name, tmp, &r[i].age);
            for(int j = 0; j < 8; j ++){
                if(tmp[0] == prolist[j]) {
                    r[i].pro = j;
                    break;
                }
            }
        }

        
        qsort(r, n, sizeof(cat), cmp);
        
        for(int i = 0; i < m && i < n ; i ++) printf("%s\n", r[i].name);
    }
    return 0;
}