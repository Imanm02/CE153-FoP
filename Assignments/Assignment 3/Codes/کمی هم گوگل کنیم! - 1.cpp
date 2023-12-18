#include "grader.h"
#include <stdio.h>
#include <stdarg.h>

#define performCalculation(a, b, operation) ((a) operation (b))

long long int findMaximum(long long int num1, long long int num2, long long int num3) {
    return (num1 >= num2 && num1 >= num3) ? num1 : (num2 >= num3) ? num2 : num3;
}

long long int findMinimum(long long int num1, long long int num2, long long int num3) {
    return (num1 <= num2 && num1 <= num3) ? num1 : (num2 <= num3) ? num2 : num3;
}

long long int sumOfAllDivisors(long long int number) {
    long long int sum = 0;
    for (long long int i = 1; i <= number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    return sum;
}

long long int sumOfProperDivisors(long long int number) {
    long long int sum = 0;
    for (long long int i = 1; i * i <= number; i++) {
        if (number % i == 0) {
            sum += i;
            if (i != number / i) {
                sum += number / i;
            }
        }
    }
    return sum;
}

#if s == 0
long long int findDivisorSum(char condition, int num1, int num2, int num3) {
    if (condition == 'M') {
        return findMaximum(sumOfProperDivisors(num1), sumOfProperDivisors(num2), sumOfProperDivisors(num3));
    } else if (condition == 'm') {
        return findMinimum(sumOfProperDivisors(num1), sumOfProperDivisors(num2), sumOfProperDivisors(num3));
    }
    return 0;
}

#else
long long int findDivisorSum(int count, ...) {
    va_list args;
    va_start(args, count);
    long long int smallestSum = sumOfAllDivisors(va_arg(args, long long int));

    for (int i = 1; i < count; i++) {
        long long int currentSum = sumOfAllDivisors(va_arg(args, long long int));
        if (currentSum < smallestSum) {
            smallestSum = currentSum;
        }
    }
    va_end(args);
    return smallestSum;
}
#endif

// Main function to run the operation
long long run(char type, int num1, int num2, int num3, int num4) {
    return findDivisorSum(type,
    performCalculation(num1, num2, +),
    performCalculation(num1, num2, -),
    performCalculation(num3, num4, *));
}