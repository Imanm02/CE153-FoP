#include <stdio.h>
#include <stdlib.h>


int maximum(int a, int b, int c)
{
    if (a >= b && a >= c) {return a;}
    else if (b >= a && b >= c) {return b;}
    else {return c;}
}
int minimum(int a, int b, int c)
{
    if (a <= b && a <= c) {return a;}
    else if (b <= a && b <= c) {return b;}
    else {return c;}
}
int medium(int a, int b, int c)
{
    if (a <= b && a >= c) {return a;}
    if (a <= c && a >= b) {return a;}
    else if (b <= a && b >= c) {return b;}
    else if (b <= c && b >= a) {return b;}
    else {return c;}
}


int main()
{
    float a1, a2, a3;
    int  point1, point2, point3, Rmin, Rmax, Rmed, n, i, j;
    int num1=0;
    scanf("%f%*s %f%*s %f%*s", &a1, &a2, &a3);
    if (a1==a2 || a1==a3 || a2==a3) {printf("error");}
    else {
        scanf("%d %d %d", &point1, &point2, &point3);
        scanf("%d", &Rmin);
        Rmax = Rmin * maximum(a1, a2, a3) / minimum(a1, a2, a3);
        Rmed = Rmin * medium(a1, a2, a3) / minimum(a1, a2, a3);
        scanf("%d", &n);
        for (int o=0; o<n; o++) {
            scanf("%d %d", &i, &j);
            if ((i*i + j*j) <= (Rmin * Rmin)) {
                num1 += maximum(point1, point2, point3);}
            else if ((i*i + j*j) <= (Rmed * Rmed)) {
                num1 += medium(point1, point2, point3);}
            else if ((i*i + j*j) <= (Rmax * Rmax)) {
                num1 += minimum(point1, point2, point3);}
            }
        printf("%d", num1);
    }
    return 0;
}

