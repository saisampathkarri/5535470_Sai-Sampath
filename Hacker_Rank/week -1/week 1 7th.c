#include <stdio.h>
#include <stdlib.h> // for abs()

int diagonalDifference(int n, int arr[n][n]) {
    int primary = 0, secondary = 0;
    for (int i = 0; i < n; i++) {
        primary += arr[i][i];
        secondary += arr[i][n - i - 1];
    }
    return abs(primary - secondary);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int result = diagonalDifference(n, arr);
    printf("%d\n", result);

    return 0;
}