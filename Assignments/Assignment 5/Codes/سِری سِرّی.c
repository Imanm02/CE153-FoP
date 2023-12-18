#include <stdio.h>
#include <stdlib.h>

void displayBitsInRange(int start, int end);
void updateBitsInRange(int start, int end, int value);

char bitArray[33554432];
char initialBits[32] = {0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1};

int main() {
    int length;
    scanf("%d", &length);

    // Initialize bit array
    for (int i = 0; i < length; i++) {
        bitArray[i] = initialBits[i % 32];
    }

    char command[6];
    while (1) {
        scanf("%s", command);
        if (command[0] == 'K') return 0;
        else if (command[0] == 'G') displayBitsInRange();
        else if (command[0] == 'A') updateBitsInRange();
    }
    return 0;
}

void displayBitsInRange() {
    int start, end;
    scanf("%d%d", &start, &end);
    for (int i = start; i <= end; i++) {
        printf("%d", bitArray[i - 1]);
    }
    printf("\n");
}

void updateBitsInRange() {
    int start, end, value;
    scanf("%d%d%d", &start, &end, &value);
    for (int i = start; i <= end; i++) {
        bitArray[i - 1] = value;
    }
    printf("\n");
}