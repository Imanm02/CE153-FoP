#include <stdio.h>
#include <stdlib.h>

long long isPrime(long long n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

long long countDivisors(long long n) {
    long long count = 0;
    for (long long i = 1; i <= n; i++) {
        if (n % i == 0) count++;
    }
    return count;
}

long long digitLength(long long n) {
    return (n == 0) ? 1 : (long long)log10(n) + 1;
}

long long productOfDigits(long long n) {
    long long product = 1;
    while (n > 0) {
        product *= n % 10;
        n /= 10;
    }
    return product;
}

long long countPrimeDivisors(long long n) {
    long long count = 0;
    for (long long i = 2; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) count++;
    }
    return count;
}

long long rotateRight(long long n) {
    int lastDigit = n % 10;
    n /= 10;
    int digits = digitLength(n);
    return lastDigit * pow(10, digits) + n;
}

long long isCircularPrime(long long n) {
    for (int i = 0; i < digitLength(n); i++) {
        if (!isPrime(n)) return 0;
        n = rotateRight(n);
    }
    return 1;
}

long long sumOfDigits(long long n) {
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long absoluteValue(long long n) {
    return (n < 0) ? -n : n;
}

long long sumOfPrimeDivisors(long long n) {
    long long sum = 0;
    for (long long i = 2; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) sum += i;
    }
    return sum;
}

int main() {
    long long n, a, b, c, d, e, output, value, maxRatio = -99999999;
    long long bestOption;
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);

        // Compute output value
        output = (b == 0) ? 0 : (isCircularPrime(b) ? sumOfDigits(b) : -countPrimeDivisors(b));

        long long diff = d - e;
        if (diff == 0) {
            value = 0;
        } else {
            long long divisorCount = countDivisors(absoluteValue(diff));
            if (absoluteValue(diff) % divisorCount == 0) {
                value = (diff > 0) ? productOfDigits(diff) : -productOfDigits(-diff);
            } else {
                value = (diff > 0) ? sumOfPrimeDivisors(diff) : -sumOfPrimeDivisors(-diff);
            }
        }

        printf("%lld%%\n", value + output);
        float ratio = (float)(value + output) / c;
        if (ratio > maxRatio) {
            maxRatio = ratio;
            bestOption = a;
        }
    }
    printf("Best option: %lld", bestOption);

    return 0;
}