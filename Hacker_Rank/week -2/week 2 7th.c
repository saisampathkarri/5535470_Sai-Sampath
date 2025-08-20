#include <stdio.h>
int isPowerOfTwo(unsigned long long n) {
    return (n && !(n & (n - 1)));
}
unsigned long long highestPowerOf2(unsigned long long n) {
    unsigned long long p = 1;
    while (p * 2 < n) {
        p *= 2;
    }
    return p;
}

int main() {
    int t;
    scanf("%d", &t);  
    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);

        int count = 0; 

        while (n > 1) {
            if (isPowerOfTwo(n)) {
                n /= 2;
            } else {
                n -= highestPowerOf2(n);
            }
            count++;
        }

        if (count % 2 == 1) {
            printf("Louise\n");
        } else {
            printf("Richard\n");
        }
    }

    return 0;
}