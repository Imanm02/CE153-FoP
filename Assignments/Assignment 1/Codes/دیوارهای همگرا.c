#include <stdio.h>
#include <stdlib.h>

int main() {
    char chars[13];
    int shiftAmount, i;

    for (i = 0; i < 13; i++) {
        scanf("%c", &chars[i]);
    }
    scanf("%d", &shiftAmount);

    for (i = 0; i < 13; i++) {
        printf("%c", chars[i] + shiftAmount);
    }

    return 0;
}