#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n, q;
    
    // Read number of input strings
    scanf("%d", &n);
    char strings[n][101];  // assume max length 100
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    // Read number of queries
    scanf("%d", &q);
    char queries[q][101];
    for (int i = 0; i < q; i++) {
        scanf("%s", queries[i]);
    }

    // Process each query
    for (int i = 0; i < q; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(queries[i], strings[j]) == 0) {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}