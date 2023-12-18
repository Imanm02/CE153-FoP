#include <stdio.h>
#include <stdlib.h>

void calculateSum(long long int num);
long long int totalSum = 0;

int main() {
    int numCases;
    long long int value;
    scanf("%d", &numCases);

    for (int i = 1; i <= numCases; i++) {
        scanf("%lld", &value);
        calculateSum(value);
        printf("%lld\n", totalSum);
        totalSum = 0;
    }
    return 0;
}

void calculateSum(long long int num) {
    if (num > 0) {
        // Direct mapping for specific cases
        int directValues[] = {0, 1, 1, 2, 3, 2, 4, 3, 5, 4};
        if (num <= 9) totalSum += directValues[num];
        else if (num % 4 == 0) {
            totalSum += 1;
            calculateSum(num - 2);
        } else if (num % 2 == 0) {
            totalSum += num / 2;
            calculateSum((num / 2) - 1);
        } else {
            totalSum += 1;
            calculateSum((num % 4 == 1) ? num - 2 : (num - 1) / 2);
        }
    }
}