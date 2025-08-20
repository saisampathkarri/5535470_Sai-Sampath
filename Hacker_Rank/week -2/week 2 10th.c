#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} Sequence;

void append(Sequence *seq, int value) {
    if (seq->size == seq->capacity) {
        seq->capacity = seq->capacity == 0 ? 1 : seq->capacity * 2;
        seq->data = realloc(seq->data, seq->capacity * sizeof(int));
    }
    seq->data[seq->size++] = value;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    Sequence *arr = malloc(n * sizeof(Sequence));
    for (int i = 0; i < n; i++) {
        arr[i].data = NULL;
        arr[i].size = 0;
        arr[i].capacity = 0;
    }

    int lastAnswer = 0;
    int *answers = malloc(q * sizeof(int));
    int ansCount = 0;

    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            append(&arr[idx], y);
        } else if (type == 2) {
            lastAnswer = arr[idx].data[y % arr[idx].size];
            answers[ansCount++] = lastAnswer;
        }
    }

    for (int i = 0; i < ansCount; i++) {
        printf("%d\n", answers[i]);
    }

    for (int i = 0; i < n; i++) {
        free(arr[i].data);
    }
    free(arr);
    free(answers);

    return 0;
}
------------------------------------------------------------------------------------
**GRID CHALLANGE
CODE:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpChar(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

const char* gridChallenge(int n, char grid[][n+1]) {
    for (int i = 0; i < n; i++) {
        qsort(grid[i], n, sizeof(char), cmpChar);
    }

    for (int col = 0; col < n; col++) {
        for (int row = 1; row < n; row++) {
            if (grid[row][col] < grid[row-1][col]) {
                return "NO";
            }
        }
    }
    return "YES";
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        char grid[n][n+1];

        for (int i = 0; i < n; i++) {
            scanf("%s", grid[i]);
        }

        printf("%s\n", gridChallenge(n, grid));
    }

    return 0;
}