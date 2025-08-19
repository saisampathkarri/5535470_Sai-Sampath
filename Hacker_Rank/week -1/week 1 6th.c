#include <stdio.h>
#include <stdint.h>

unsigned int flippingBits(unsigned int n) {
    return n ^ 0xFFFFFFFF;  // flip all 32 bits
}

int main() {
    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        unsigned int n;
        scanf("%u", &n);
        printf("%u\n", flippingBits(n));
    }

    return 0;
}
