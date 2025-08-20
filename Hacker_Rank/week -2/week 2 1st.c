#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int socks[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &socks[i]);
    }
    int colorCount[101] = {0}; 
    for (int i = 0; i < n; i++) {
        colorCount[socks[i]]++;
    }
    int pairs = 0;
    for (int i = 1; i <= 100; i++) {
        pairs += colorCount[i] / 2;
    }
    printf("%d\n", pairs);
    return 0;
}