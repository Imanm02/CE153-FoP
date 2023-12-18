#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    scanf("%d", &size);
    int matrix[size][size];

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }

    for (int sum = 0; sum <= (2 * size) - 2; sum++) {
        if (sum % 2 == 0) {
            for (int x = size - 1; x > -1; x--) {
                for (int y = 0; y <= size - 1; y++) {
                    if (x + y == sum) printf("%d ", matrix[x][y]);
                }
            }
        } else {
            for (int x = 0; x <= size - 1; x++) {
                for (int y = size - 1; y > -1; y--) {
                    if (x + y == sum) printf("%d ", matrix[x][y]);
                }
            }
        }
    }
    return 0;
}