#include <stdio.h> 
#include <string.h> 
char str[10]; 
//11213 - permutations geeks version
/* Function to swap values at two pointers */
void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 
void show(int n)
{
    int i;
    printf("(%c", str[0]);
    for (i=1; i <= n; i++) {
        printf(",%c", str[i]);
    }
    printf(")\n");
}
/* Function to print permutations of string 
   This function takes three parameters: 
   1. String 
   2. Starting index of the string 
   3. Ending index of the string. */
void permute(char *a, int l, int r) 
{ 
   int i; 
   if (l == r) 
     show(r);
   else
   { 
       for (i = l; i <= r; i++) 
       { 
          swap((a+l), (a+i)); 
          permute(a, l+1, r); 
          swap((a+l), (a+i)); //backtrack 
       } 
   } 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int n, i;

    scanf("%s", str);

    for(i=0; i<n; i++)
        str[i] = '1'+i;
    
    permute(str, 0, n-1); 
    return 0; 
} 