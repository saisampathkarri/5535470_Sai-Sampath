#include <stdio.h>

void countingSort(int arr[], int n) {
    int freq[100] = {0};  // initialize frequency array with 0

    // Count frequencies
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print frequencies
    for (int i = 0; i < 100; i++) {
        printf("%d", freq[i]);
        if (i < 99) printf(" ");
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);
    return 0;
}