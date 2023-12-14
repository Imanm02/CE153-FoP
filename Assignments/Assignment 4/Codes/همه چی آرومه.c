#include <stdio.h>
#include <stdlib.h>
double tabe(double n, double a, double b, double c, double d, double e, double f)
{
    return (a*n*n*n*n*n + b*n*n*n*n + c*n*n*n + d*n*n + e*n +f);
}
double bazgashti(double n, double m, double a, double b, double c, double d, double e, double f)
{
    if (tabe((m+n)/2, a, b, c, d, e, f) == 0 ) {return (m+n)/2;}
    else if (tabe((m+n)/2, a, b, c, d, e, f)*tabe(n, a, b, c, d, e, f)<0) {
        return bazgashti(n, (m+n)/2, a, b, c, d, e, f);
    }
    else {
        return bazgashti(m, (m+n)/2, a, b, c, d, e, f);
    }
}
int main()
{
    double a, b, c, d, e, f, m, n;
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f, &m, &n);
    if ( tabe(m, a, b, c, d, e, f) == 0 ) { printf("%f", m);}
    else if (tabe(n, a, b, c, d, e, f)==0) {printf("%f", n);}
    else if (tabe(m, a, b, c, d, e, f) * tabe(n, a, b, c, d, e, f)>0) {
        printf("NOT POSSIBLE!");
    }
    else {printf("%f", bazgashti(n, m, a, b, c, d, e, f));}
    return 0;
}
