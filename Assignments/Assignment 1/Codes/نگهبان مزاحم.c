#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrix[3][3];
    int row, col, determinant;

    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            scanf("%d", &matrix[row][col]);
        }
    }

    determinant = matrix[0][0] * matrix[1][1] * matrix[2][2] + 
                  matrix[0][1] * matrix[1][2] * matrix[2][0] + 
                  matrix[0][2] * matrix[1][0] * matrix[2][1] - 
                  matrix[0][2] * matrix[1][1] * matrix[2][0] - 
                  matrix[0][0] * matrix[1][2] * matrix[2][1] - 
                  matrix[0][1] * matrix[1][0] * matrix[2][2];

    printf("%d", determinant);

    return 0;
}