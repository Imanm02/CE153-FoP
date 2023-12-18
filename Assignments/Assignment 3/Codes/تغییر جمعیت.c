#include <stdio.h>
#include <stdlib.h>

int isMovePossible(int x, int y) {
    if ((x == 1 && y != 1) || (x <= 3 && y > 3) || (x == 0)) {
        return 0;
    }
    return 1;
}

int main() {
    int testCases, x, y;
    scanf("%d", &testCases);
    while (testCases--) {
        scanf("%d %d", &x, &y);
        printf("%s\n", isMovePossible(x, y) ? "YES" : "NO");
    }
    return 0;
}