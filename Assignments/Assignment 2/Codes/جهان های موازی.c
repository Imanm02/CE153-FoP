#include <stdio.h>
#include <stdlib.h>

int main() {
    long long a, b, c, d;
    scanf("%lld %lld", &a, &b);
    scanf("%lld %lld", &c, &d);

    long long maxProduct = a * c;
    maxProduct = (maxProduct > b * d) ? maxProduct : b * d;
    maxProduct = (maxProduct > a * d) ? maxProduct : a * d;
    maxProduct = (maxProduct > b * c) ? maxProduct : b * c;

    printf("%lld", maxProduct);
    return 0;
}