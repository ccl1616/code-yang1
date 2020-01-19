#include <stdio.h>
#include <string.h>
#include "function.h"
//12490 - Little Brick's Calculator   
#define maxn 1000
char input[1000010];

int main() {
    int sum = 0;
    int a[maxn];
    int *ptr[maxn];

    for (int i = 0; i < maxn; i++) {
        a[i] = 0;
        ptr[i] = &a[i];
    }

    scanf("%s", input);
    int n = solver(ptr, &sum, input);
    printf("%d", a[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", a[i]);
    printf("\n");
    printf("\n%d\n", sum);
    return 0;
}