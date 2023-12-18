#include <stdio.h>
#include <stdlib.h>

int isLucky(int number) {
    while (number > 0) {
        int digit = number % 10;
        if (digit != 4 && digit != 7) {
            return 0;
        }
        number /= 10;
    }
    return 1;
}

int hasLuckyDivisor(int number) {
    for (int i = 4; i <= number; i++) {
        if (number % i == 0 && isLucky(i)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int testCases, num;
    scanf("%d", &testCases);
    while (testCases--) {
        scanf("%d", &num);
        printf("%s\n", hasLuckyDivisor(num) ? "YES" : "NO");
    }
    return 0;
}