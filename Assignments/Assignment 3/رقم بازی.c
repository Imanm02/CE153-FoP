#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    scanf("%d\n", &t);
    for (int i=0; i < t; i++) {
        long long int n;
        scanf("%lld\n", &n);
        if (amount(n)%2==0) {
                if (shans(n)) {
                        printf("2\n");
                    }
                else {printf("1\n");}
        }
        else {
                if (OPOP(n)) {
                        printf("1\n");
                    }
                else {printf("2\n");
        }
    }}
    return 0;
}
int amount(long long int a)
{
    int p=0;
     if (a == 0){
        return 1;
    }
    while(a>0)
    {
        a=a/10;
        p++;
    }
    return p;
}

int shans(long long int m){
    long long int k = m;
    int a=0;
        while (k > 0){
            if (k % 2 == 0) {
                a = 1;
        }
            k /= 100;
    }
    return a;
}

int OPOP(long long int m){
    long long int k = m;
    int a=0;
        while (k > 0){
            if (k % 2 != 0) {
                a = 1;
        }
            k /= 100;
    }
    return a;
}
