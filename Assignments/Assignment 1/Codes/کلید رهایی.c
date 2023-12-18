#include <stdio.h>
#include <stdlib.h>

int main() {
    long long int number;

    scanf("%lld", &number);
    printf("%lld", number % 9);

    return 0;
}