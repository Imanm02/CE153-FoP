#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int n, m, l;

int findMaxInt(int* array) {
    int maxSum = 0;
    for (int i = 0; i < l; i++) {
        for (int j = i + 1; j <= l; j++) {
            int sum = 0;
            for (int k = i; k < j; k++) {
                sum += array[k];
            }
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

char findMaxChar(char* array) {
    char maxChar = 0;
    for (int i = 0; i < l; i++) {
        if (array[i] > maxChar) {
            maxChar = array[i];
        }
    }
    return tolower(maxChar);
}

int main() {
    scanf("%d %d %d", &n, &m, &l);
    void*** inputArray = malloc(n * sizeof(void**));

    for (int i = 0; i < n; i++) {
        inputArray[i] = malloc(m * sizeof(void*));

        for (int j = 0; j < m; j++) {
            char dataType;
            scanf(" %c", &dataType);

            if (dataType == 'T') {
                int* intArray = malloc(l * sizeof(int));
                for (int k = 0; k < l; k++) {
                    scanf("%d", &intArray[k]);
                }
                printf("%d ", findMaxInt(intArray));
                free(intArray);
            } else {
                char* charArray = malloc(l * sizeof(char));
                for (int k = 0; k < l; k++) {
                    scanf(" %c", &charArray[k]);
                }
                printf("%c ", findMaxChar(charArray));
                free(charArray);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(inputArray[i]);
    }
    free(inputArray);
    return 0;
}