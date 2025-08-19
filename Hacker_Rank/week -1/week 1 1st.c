#include <stdio.h>

int main() {
    int n, num;
    int pos = 0, neg = 0, zero = 0;

    scanf("%d", &n);  

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);

        if (num > 0)
            pos++;
        else if (num < 0)
            neg++;
        else
            zero++;
    }

    printf("%.6f\n", (float)pos / n);
    printf("%.6f\n", (float)neg / n);
    printf("%.6f\n", (float)zero / n);

    return 0;
}