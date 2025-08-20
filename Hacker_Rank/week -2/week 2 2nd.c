#include <stdio.h>
int main() {
    int n, p;
    scanf("%d %d", &n, &p);

    int frontTurns = p / 2;
    int backTurns = (n / 2) - frontTurns;

    int result = frontTurns < backTurns ? frontTurns : backTurns;

    printf("%d\n", result);

    return 0;
}