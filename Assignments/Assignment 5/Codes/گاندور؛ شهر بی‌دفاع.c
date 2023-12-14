#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long int a, n;
    long long int  sort[100005];
    for (long long int j = 0; j <= 100000; j++) {
        sort[j]  = 0;
    }
    scanf("%lld", &n);
    for (long long int i = 1; i <= n; i++) {
        scanf("%lld", &a);
        sort[a] += 1;
    }
    long long int majmoo[100005];
    for (long long int k = 0; k <= 100000; k++) {
        majmoo[k] = k * sort[k];
    }
    for (long long int p = 2; p <= 100000; p++) {
        if (majmoo[p] + majmoo[p-2] > majmoo[p-1]) {
            majmoo[p] = majmoo[p] + majmoo[p-2];
        }
        else {
            majmoo[p] = majmoo[p-1];
        }
    }
    if (majmoo[100000] > majmoo[99999]) {
        printf("%lld", majmoo[100000]);
    }
    else {printf("%lld", majmoo[99999]);}

    return 0;
}
