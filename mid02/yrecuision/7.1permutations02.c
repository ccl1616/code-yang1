#include <stdio.h>
//11213 - permutations
char list[10];

void show(int n)
{
    int i;
    printf("(%c", list[0]);
    for (i = 1; i <= n; i ++) {
        printf(",%c", list[i]);
    }
    printf(")\n");
}

//swap the first element
void swap(char *k, char *q)
{
    char temp;
    temp = *k;
    *k = *q;
    *q = temp;
}

//perm and print each times
void perm(char k, char n) //k = the first one to swap, n = num of elements
{
    if(k == n) show(n);
    else{  
        for(int i = k; i <= n; i ++){
            swap(&list[k], &list[i]);
            perm(k + 1, n);
            swap(&list[k], &list[i]);
        }
    }
}

int main(void)
{
    int num, i;
    scanf("%d", &num);
    for(i = 0; i < num; i++)
        list[i] = '1' + i;
    perm(0, num - 1);
    return 0;
}
