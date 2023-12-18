#include <stdio.h>
#include <stdlib.h>

int computeFirstFunction(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return computeFirstFunction(n / 2) + computeFirstFunction(n / 3) + n * n;
}

int computeSecondFunction(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return computeSecondFunction(n / 2) + computeSecondFunction(n / 3) + 2 * n * n;
}

int main() {
    int number;
    scanf("%d", &number);
    if (number < 500 || number == 0 || number == 1) printf("%d", computeFirstFunction(number));
    else if (number >= 500) printf("%d", computeSecondFunction(number));
    return 0;
}