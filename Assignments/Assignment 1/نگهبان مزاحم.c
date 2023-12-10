#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e,f,g,h,i,determinan;
    
    scanf("%d%d%d", &a,&b,&c);
    scanf("%d%d%d", &d,&e,&f);
    scanf("%d%d%d", &g,&h,&i);

    determinan=a*e*i+b*f*g+c*d*h+(~c+1)*e*g+(~a+1)*f*h+(~b+1)*d*i;

    printf("%d",determinan);

    return 0;
}