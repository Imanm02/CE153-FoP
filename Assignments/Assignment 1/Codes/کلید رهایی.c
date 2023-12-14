#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int num;

    scanf("%ld", &num);

    printf("%ld", num%9);

    return 0;
}