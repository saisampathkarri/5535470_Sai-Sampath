#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);
    if (!data) return NULL;

    while (true) {
        char* cursor = data + data_length;
        if (fgets(cursor, alloc_length - data_length, stdin) == NULL) break;

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;

        alloc_length <<= 1;
        char* temp = realloc(data, alloc_length);
        if (!temp) {
            free(data);
            return NULL;
        }
        data = temp;
    }

    if (data_length > 0 && data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
        char* temp = realloc(data, data_length);
        if (temp) data = temp;
    } else {
        char* temp = realloc(data, data_length + 1);
        if (temp) {
            data = temp;
            data[data_length] = '\0';
        }
    }

    return data;
}

int superDigit(char* n, int k) {
    long long sum = 0;
    for (int i = 0; n[i] != '\0'; i++) {
        sum += (n[i] - '0');
    }
    sum *= k;

    while (sum > 9) {
        long long temp = 0;
        while (sum > 0) {
            temp += sum % 10;
            sum /= 10;
        }
        sum = temp;
    }

    return (int)sum;
}

int main() {
    char* input = readline();
    if (!input) return 1;

    char* token = strtok(input, " ");
    char* n = token;
    token = strtok(NULL, " ");
    int k = atoi(token);

    int result = superDigit(n, k);
    printf("%d\n", result);

    free(input);
    return 0;
}