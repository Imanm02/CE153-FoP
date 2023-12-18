#include <stdio.h>
#include <stdlib.h>

int main() {
    const int MAX_SIZE = 100005;
    long long int num, count[MAX_SIZE] = {0}, maxSum[MAX_SIZE];

    scanf("%lld", &num);
    for (long long int i = 1; i <= num; i++) {
        long long int value;
        scanf("%lld", &value);
        count[value]++;
    }

    for (long long int i = 0; i < MAX_SIZE; i++) {
        maxSum[i] = i * count[i];
    }

    for (long long int i = 2; i < MAX_SIZE; i++) {
        maxSum[i] = (maxSum[i] + maxSum[i-2] > maxSum[i-1]) ? maxSum[i] + maxSum[i-2] : maxSum[i-1];
    }

    printf("%lld", maxSum[MAX_SIZE - 1] > maxSum[MAX_SIZE - 2] ? maxSum[MAX_SIZE - 1] : maxSum[MAX_SIZE - 2]);
    return 0;
}