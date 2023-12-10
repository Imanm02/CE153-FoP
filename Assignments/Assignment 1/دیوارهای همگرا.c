#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b,c,d,e,f,g,h,i,j,k,l,m;
    int n;
    scanf("%c%c%c%c%c%c%c%c%c%c%c%c%c%*s%d",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l,&m,&n);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c",a+n,b+n,c+n,d+n,e+n,f+n,g+n,h+n,i+n,j+n,k+n,l+n,m+n);
    return 0;
}
