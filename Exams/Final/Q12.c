#include <stdio.h>
#include <stdlib.h>
int len(int n){
    if (n <= 9 && n >= 0){
        return 1;
    }
    return 1 + len(n / 10);
}
int main()
{
    int b, c, d;
    scanf("%d%d", &c, &b);
    d = len(b) * len(c);
    printf("%d", d);
    return 0;
}
