#include <stdio.h>
#include <stdlib.h>
int tabe1(int n)
{
    if (n==0) {return 0;}
    else if (n==1) {return 1;}
    else {return (tabe1(n/2) + tabe1(n/3) + n*n);}
}
int tabe2(int n)
{
    if (n==0) {return 0;}
    else if (n==1) {return 1;}
    else {return (tabe2(n/2) + tabe2(n/3) + 2*n*n);}
}
int main()
{
    int a;
    scanf("%d", &a);
    if (a<500 || a==0 || a==1) {printf("%d", tabe1(a));}
    else if (a>=500) {printf("%d", tabe2(a));}
    return 0;
}
