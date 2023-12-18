#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int base;
    char *num1 = calloc(10000, sizeof(char)), *num2 = calloc(10000, sizeof(char));
    scanf("%d %s %s", &base, num1, num2);

    int len1 = strlen(num1), len2 = strlen(num2);
    int maxLength = (len1 > len2) ? len1 : len2;
    char *result = calloc(maxLength + 2, sizeof(char));

    // Pad the shorter number with zeros
    if (len1 != len2) {
        char *temp = calloc(maxLength, sizeof(char));
        strcpy(temp + maxLength - ((len1 > len2) ? len1 : len2), (len1 > len2) ? num2 : num1);
        strcpy((len1 > len2) ? num2 : num1, temp);
        free(temp);
    }

    int carry = 0;
    for (int i = maxLength - 1; i >= 0; i--) {
        int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        result[i + 1] = (sum % base) + '0';
        carry = sum / base;
    }
    result[0] = carry + '0';

    printf("%s", (result[0] != '0') ? result : result + 1);

    free(num1);
    free(num2);
    free(result);
    return 0;
}