#include <stdio.h>
#include <stdlib.h>

int main(){

    long long int n = 0;
    int t = 0, sas = 0;
    long long int a = 0, p = 0, s = 0;
    long long int a1 = 0, a2 = 0, b1 = 0, b2 =0;
    char c;
    int moves = 0;

    scanf("%d", &t);
    for(int i = t; i > 0; i--){
        scanf("%ld", &n);
        moves = 0;
        scanf("%lld%*c", &a);
        if(n != 1){
        a2 = a;
        scanf("%lld%*c", &a);
        a1 = a;
        for(long int e = n; e > 2; e--){
            scanf("%lld%*c", &a);
            if(a==a1){
                a2==a1;
                continue;
            }
            b2 = a - a1;
            b1 = a1 - a2;
            if(b1 * b2 < 0){
                moves++;
            }
            a2 = a1;
            a1 = a;
        }
        if(moves < 2){
            sas = 1;
        } else {
            sas = 0;
        }
        p = sas << i;
        s = p + s;
        } else {
        p = 1 << i;
        s = p + s;
        }
    }
    for(int i = t; i > 0; i--){
        p = 1 << i;
        sas = s / p;

        s = s % p;
        if(sas == 1){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    } return 0;
}
