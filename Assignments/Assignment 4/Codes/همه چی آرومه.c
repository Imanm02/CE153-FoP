#include <stdio.h>
#include <stdlib.h>

double polynomialFunction(double n, double a, double b, double c, double d, double e, double f) {
    return a * n * n * n * n * n + b * n * n * n * n + c * n * n * n + d * n * n + e * n + f;
}

double findRoot(double left, double right, double a, double b, double c, double d, double e, double f) {
    double mid = (left + right) / 2;
    double midValue = polynomialFunction(mid, a, b, c, d, e, f);

    if (midValue == 0) return mid;
    else if (midValue * polynomialFunction(left, a, b, c, d, e, f) < 0) 
        return findRoot(left, mid, a, b, c, d, e, f);
    else 
        return findRoot(mid, right, a, b, c, d, e, f);
}

int main() {
    double a, b, c, d, e, f, left, right;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f, &left, &right);

    if (polynomialFunction(left, a, b, c, d, e, f) == 0) printf("%f", left);
    else if (polynomialFunction(right, a, b, c, d, e, f) == 0) printf("%f", right);
    else if (polynomialFunction(left, a, b, c, d, e, f) * polynomialFunction(right, a, b, c, d, e, f) > 0)
        printf("NOT POSSIBLE!");
    else printf("%f", findRoot(right, left, a, b, c, d, e, f));

    return 0;
}