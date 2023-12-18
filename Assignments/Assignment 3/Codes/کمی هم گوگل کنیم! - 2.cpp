#include "grader.h"
#include <stdio.h>
#include <stdarg.h>

#define calc(a, b, operation) ((a) operation (b))

long long int findMaximum(long long int num1, long long int num2, long long int num3) {
    if (num1 >= num2 && num1 >= num3) return num1;
    return (num2 >= num3) ? num2 : num3;
}

long long int findMinimum(long long int num1, long long int num2, long long int num3) {
    if (num1 <= num2 && num1 <= num3) return num1;
    return (num2 <= num3) ? num2 : num3;
}

long long int sumOfDivisors(long long int number) {
    long long int sum = 0;
    for (long long int i = 1; i <= number; i++) {
        if (number % i == 0) sum += i;
    }
    return sum;
}

long long int sumOfProperDivisors(long long int number) {
    long long int sum = 0;
    for (long long int i = 1; i * i <= number; i++) {
        if (number % i == 0) {
            sum += i;
            if (i * i != number) sum += number / i;
        }
    }
    return sum;
}

#if s == 0
long long int findDivisorSum(char type, int num1, int num2, int num3) {
    if (type == 'M') {
        return findMaximum(sumOfProperDivisors(num1), sumOfProperDivisors(num2), sumOfProperDivisors(num3));
    } else if (type == 'm') {
        return findMinimum(sumOfProperDivisors(num1), sumOfProperDivisors(num2), sumOfProperDivisors(num3));
    }
    return 0;
}

#else
long long int findDivisorSum(int count, ...) {
    va_list args;
    va_start(args, count);
    long long int minSum = sumOfDivisors(va_arg(args, long long int));
    for (int i = 1; i < count; i++) {
        long long int currentSum = sumOfDivisors(va_arg(args, long long int));
        if (currentSum < minSum) minSum = currentSum;
    }
    va_end(args);
    return minSum;
}
#endif

long long run(char type, int num1, int num2, int num3, int num4) {
    return findDivisorSum(type,
                          calc(num1, num2, +),
                          calc(num1, num2, -),
                          calc(num3, num4, *));
}