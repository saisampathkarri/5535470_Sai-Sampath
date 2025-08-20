#include <stdio.h>

long sumXor(long n) {
    if (n == 0) return 1;
    long zeros = 0;
    while (n) {
        if ((n & 1) == 0) zeros++;
        n >>= 1;
    }
    return 1L << zeros;
}

int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld\n", sumXor(n));
    return 0;
}