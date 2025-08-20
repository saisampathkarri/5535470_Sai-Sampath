#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    int min_unfairness = INT_MAX;
    for (int i = 0; i <= n - k; i++) {
        int unfairness = arr[i + k - 1] - arr[i];
        if (unfairness < min_unfairness) {
            min_unfairness = unfairness;
        }
    }

    printf("%d\n", min_unfairness);

    return 0;
}
-------------------------------------------------------------------------------------
**DYNAMIC ARRAY
CODE:

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