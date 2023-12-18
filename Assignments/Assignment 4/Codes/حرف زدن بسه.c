#include <stdio.h>
#include <stdlib.h>

void printPattern(int n) {
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {
            if (i == 1 || j == 2 * n - i + 1) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
}

void repeatPattern(int n) {
    if (n > 0) {
        printPattern(n);
        repeatPattern(n - 1);
    }
}

int main() {
    int size;
    scanf("%d", &size);
    repeatPattern(size);
    return 0;
}