#include <stdio.h>
#include <string.h>

void timeConversion(char *s) {
    int hour, minute, second;
    char meridian[3];

    // Parse input string "hh:mm:ssAM/PM"
    sscanf(s, "%2d:%2d:%2d%2s", &hour, &minute, &second, meridian);

    // Convert hour depending on AM/PM
    if (strcmp(meridian, "AM") == 0) {
        if (hour == 12) hour = 0;  // Midnight case
    } else { // PM
        if (hour != 12) hour += 12;  // Convert to 24-hour format
    }

    // Print in 24-hour format
    printf("%02d:%02d:%02d\n", hour, minute, second);
}

int main() {
    char s[11];  // "hh:mm:ssAM" = 10 chars + null terminator
    scanf("%s", s);

    timeConversion(s);
    return 0;
}