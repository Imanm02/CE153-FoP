#include <stdio.h>
#include <stdlib.h>

int digitCount(long long n) {
    int count = 0;
    do {
        count++;
        n /= 10;
    } while (n > 0);
    return count;
}

int hasEvenDigitEveryOther(long long n) {
    while (n > 0) {
        if ((n % 100) / 10 % 2 == 0) return 1;
        n /= 100;
    }
    return 0;
}

int hasOddDigitEveryOther(long long n) {
    while (n > 0) {
        if ((n % 100) / 10 % 2 != 0) return 1;
        n /= 100;
    }
    return 0;
}

int main() {
    int testCases;
    scanf("%d", &testCases);
    while (testCases--) {
        long long n;
        scanf("%lld", &n);

        if (digitCount(n) % 2 == 0) {
            printf("%d\n", hasEvenDigitEveryOther(n) ? 2 : 1);
        } else {
            printf("%d\n", hasOddDigitEveryOther(n) ? 1 : 2);
        }
    }
    return 0;
}