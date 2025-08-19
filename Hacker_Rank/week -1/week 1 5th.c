#include <stdio.h>

int lonelyinteger(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];  // XOR all elements
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int answer = lonelyinteger(arr, n);
    printf("%d\n", answer);

    return 0;
}