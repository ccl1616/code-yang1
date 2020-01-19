#include <stdio.h>
//12439-little-brick's-function
int gcd(int a, int b) {
    int max;
    if(a > b) max = a;
    else max = b;
    int gcdmax;
    for(int i = 1; i <= max; i ++){
        if(a % i == 0 && b % i == 0) gcdmax = i;
    }
    return gcdmax;
}

int lcm(int a, int b) {
    int ans;
	for(int i = 1; i <= a*b; i ++){
        if(i % a == 0 && i % b == 0) {
            ans = i;
            break;
        }
    }
    return ans;
}

int power(int a, int b) {
    int ans = 1;
	for(int i = 1; i <= b; i ++){
        ans = ans * a;
    }
    return ans;
}

int main() {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	printf("%d\n", gcd(lcm(power(a, b), c), d));
	printf("%d\n", gcd(power(lcm(a, b), c), d));
    printf("%d\n", lcm(gcd(power(a, b), c), d));
    printf("%d\n", lcm(power(gcd(a, b), c), d));
    printf("%d\n", power(gcd(lcm(a, b), c), d));
    printf("%d\n", power(lcm(gcd(a, b), c), d));
	return 0;
}