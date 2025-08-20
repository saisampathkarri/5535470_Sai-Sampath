#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n, k;
    scanf("%d", &n);            
    char s[n + 1];
    scanf("%s", s);            
    scanf("%d", &k);            

    k = k % 26; 
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (isupper(c)) {
            s[i] = ((c - 'A' + k) % 26) + 'A';
        } else if (islower(c)) {
            s[i] = ((c - 'a' + k) % 26) + 'a';
        }
    }

    printf("%s\n", s);
    return 0;
}