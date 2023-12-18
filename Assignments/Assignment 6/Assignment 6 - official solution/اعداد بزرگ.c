#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 10010

void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char* sumInRadix(char* num1, char* num2, int radix) {
    reverseString(num1);
    reverseString(num2);
    char* result = calloc(MAX_LENGTH, sizeof(char));

    int carry = 0;
    for (int i = 0; i < MAX_LENGTH - 1; i++) {
        int digitSum = carry;
        if (num1[i]) digitSum += num1[i] - '0';
        if (num2[i]) digitSum += num2[i] - '0';
        result[i] = (digitSum % radix) + '0';
        carry = digitSum / radix;
    }
    reverseString(result);

    return result;
}

int main() {
    int radix;
    scanf("%d", &radix);
    char num1[MAX_LENGTH], num2[MAX_LENGTH];
    scanf("%s %s", num1, num2);
    
    char* sumResult = sumInRadix(num1, num2, radix);
    printf("%s", sumResult);
    free(sumResult);

    return 0;
}