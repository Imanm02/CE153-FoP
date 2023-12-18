#include <stdio.h>
#include <stdlib.h>

int main() {
    int testCases;
    scanf("%d", &testCases);

    long long sequenceLength, currentValue, previousValue, prePreviousValue;
    int zigZagCount, isZigZag;
    long long answer = 0, powerOfTwo;

    for (int i = 0; i < testCases; i++) {
        scanf("%lld", &sequenceLength);

        zigZagCount = 0;

        if (sequenceLength > 1) {
            scanf("%lld", &previousValue);
            scanf("%lld", &currentValue);

            for (int j = 0; j < sequenceLength - 2; j++) {
                prePreviousValue = previousValue;
                previousValue = currentValue;
                scanf("%lld", &currentValue);

                if ((currentValue - previousValue) * (previousValue - prePreviousValue) < 0) {
                    zigZagCount++;
                }
            }

            isZigZag = (zigZagCount < 2) ? 1 : 0;
        } else {
            isZigZag = 1;
        }

        powerOfTwo = 1LL << (testCases - i - 1);
        answer += isZigZag * powerOfTwo;
    }

    for (int i = testCases; i > 0; i--) {
        powerOfTwo = 1LL << (testCases - i);
        isZigZag = answer / powerOfTwo;
        answer %= powerOfTwo;

        printf("%s\n", isZigZag ? "YES" : "NO");
    }

    return 0;
}