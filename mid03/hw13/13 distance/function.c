#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"

Point * ones_vec_1(int length)
{
   /// Please implement
   /// 1. Malloc memory for point array
   Point *a;
   a = (Point*) malloc (length * sizeof(Point));
   int i;
   /// 2. Read values into point array
   for(i = 0; i < length; i ++){
       scanf("%d %d",&a[i].x,&a[i].y);
   }
   /// 3. Return the address of the first element in the array
    return a;
}

float compute_distance(Point* a, int first_id, int second_id)
{
    float ans;
    Point first_p, second_p;

    /// Please implement
    /// 1. Get two point from function argument
    first_p.x = a[first_id].x;
    first_p.y = a[first_id].y;
    second_p.x = a[second_id].x;
    second_p.y = a[second_id].y;
    /// 2. Compute 2D distance and return ans
    // a*a or use pow(a,2)
    ans = sqrt( (first_p.x - second_p.x)*(first_p.x - second_p.x) + (first_p.y - second_p.y)*(first_p.y - second_p.y) );
    return ans;
}