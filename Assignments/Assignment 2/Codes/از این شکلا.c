#include <stdio.h>
#include <stdlib.h>

void printLine(int spaceCount, int starCount) {
    for (int i = 0; i < spaceCount; i++) {
        printf("  ");
    }
    for (int i = 0; i < starCount; i++) {
        printf("* ");
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 2 * n; i++) {
        if (i < n) {
            printLine(n - i - 1, i + 1);
        } else {
            printLine(i - n, 2 * n - i);
        }
    }

    return 0;
}