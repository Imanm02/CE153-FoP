#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a, b, c, d, g, e, t;

    scanf("%lld%lld", &a, &b);
    scanf("%lld%lld", &c, &d);

    if (a*c>b*d){
        g=a*c;
    }
    else{
        g=b*d;
    }
    
    if (g>a*d){
        e=g;
    }
    else{
        e=a*d;
    }

    if (e>b*c){
        t=e;
    }
    else{
        t=b*c;
    }

    printf("%lld", t);
    return 0;
}