#include <stdio.h>
#include <stdlib.h>

int main() {
    int patternLength, sequenceLength;
    scanf("%d %d", &patternLength, &sequenceLength);

    int patternValue = 0, sequenceValue = 0;
    char ch;

    for (int i = 0; i < patternLength; i++) {
        scanf(" %c", &ch);
        patternValue = patternValue * 10 + (ch - 'a' + 1);
    }

    for (int i = 0; i < sequenceLength; i++) {
        scanf(" %c", &ch);
        sequenceValue = sequenceValue * 10 + (ch - 'a' + 1);
    }

    int multiplier = 1;
    for (int i = 0; i < sequenceLength; i++) {
        multiplier *= 10;
    }

    int matchIndex = -1;
    for (int i = 0; i <= patternLength - sequenceLength; i++) {
        if (patternValue % multiplier == sequenceValue) {
            matchIndex = i;
            break;
        }
        patternValue /= 10;
    }

    printf("%d", matchIndex);
    return 0;
}