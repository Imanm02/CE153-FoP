#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int n, m, l;

int findMaxSumInArray(int* array) {
    int maxSum = 0;
    for (int start = 0; start < l; start++) {
        for (int end = start + 1; end <= l; end++) {
            int currentSum = 0;
            for (int index = start; index < end; index++) {
                currentSum += array[index];
            }
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}

char findMaxCharInArray(char* array) {
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
    void*** arr = malloc(n * sizeof(void**));
    int** results = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        arr[i] = malloc(m * sizeof(void*));
        results[i] = malloc(m * sizeof(int));

        for (int j = 0; j < m; j++) {
            char type;
            scanf(" %c", &type);

            if (type == 'T') {
                int* intArray = malloc(l * sizeof(int));
                for (int k = 0; k < l; k++) {
                    scanf("%d", &intArray[k]);
                }
                results[i][j] = findMaxSumInArray(intArray);
                free(intArray);
            } else {
                char* charArray = malloc(l * sizeof(char));
                for (int k = 0; k < l; k++) {
                    scanf(" %c", &charArray[k]);
                }
                results[i][j] = findMaxCharInArray(charArray);
                free(charArray);
            }

            printf("%c ", results[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
        free(results[i]);
    }
    free(arr);
    free(results);
    return 0;
}