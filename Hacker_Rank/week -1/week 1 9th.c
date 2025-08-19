#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* pangrams(char* s) {
    int seen[26] = {0};
    int unique = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            int idx = tolower(s[i]) - 'a';
            if (!seen[idx]) {
                seen[idx] = 1;
                unique++;
            }
        }
    }

    if (unique == 26)
        return "pangram";
    else
        return "not pangram";
}

int main() {
    char s[1000];   // string can be up to 10^3 chars
    fgets(s, sizeof(s), stdin);

    // Remove trailing newline if present
    size_t len = strlen(s);
    if (len > 0 && s[len-1] == '\n') {
        s[len-1] = '\0';
    }

    printf("%s\n", pangrams(s));
    return 0;
}