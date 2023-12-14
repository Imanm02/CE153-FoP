#include <stdio.h>
#include <stdlib.h>

long long int aval(long long int n){

    if (n == 1) {return 0;}
    else if (n == 2) {return 1;}
    for(int i=2;i<=n/2;i++){
    if (n % i == 0) {return 0;}
}
return 1;
}
long long int tedadmaghsoom(long long int n) {
    int p=2;
    if (n==1) {return 1;}
    for (long long int i=2; i<=n/2; i++){
        if (n%i==0) {p += 1;}
        else {p += 0;}
    }
    return p;
}


long long int len(long long int n){
    int c = 0;
    if (n == 0){
        return 1;}
    while (n >= 1){
        n = n / 10;
        c += 1;
    }
    return c;
}


long long int zarbargham(long long int n){
    long long int m = 1;
    int help = len(n);
    for (int i=1; i <= help; i++){
        m *= n%10;
        n /= 10;
    }

    return m;
}

long long int tedadmaghsoomaval(long long int n) {
    int p=0;
    for (int i=2; i<=n; i++){
        if (n%i==0 && tedadmaghsoom(i)==2) {p += 1;}
    }
    return p;
}

long long int shiftr(long long int n){
    int m = n;
    m = m/10;
    int c = 1;
    int help = len(n);
    for(int i = 0;i<help-1;i++){
        c *= 10;
    }
    m = m + (n%10)*c;
    return m;
}
long long int halghavi(long long int n){
    int i;
    int help = len(n);
    for(i=0;i<help;i++){
        if (!aval(n)) {return 0;}
        n = shiftr(n);
    }
    return 1;
}

long long int majmooargham(long long int n) {
    int m = 0;
    int help = len(n);
    for (int i=1; i <= help; i++){
        m += n%10;
        n /= 10;
    }

    return m;
}

long long int ghadrmotlagh(long long int a){
if (a < 0) {return (-1 * a);}
return a;
}

long long int majmoomaghsoomaval(long long int n) {
    int p=0;
    for (int i=2; i<=n; i++){
        if (n%i==0 && tedadmaghsoom(i)==2) {p += i;}
    }
    return p;
}


int main()
{
    float g;
    long long int n, a, b, c, d, e, o, q, w;
    float k=-99999999;
    scanf("%lld", &n);
    int i;
    for (i=1; i<=n; i++) {
        scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &e);
        if (b==0) {o = 0;}
        else if (halghavi(b)) {o = majmooargham(b);}
        else {o = -1 * tedadmaghsoomaval(b);}


        long long int x = d - e;
        if (x==0) {q=0;}

        else if (x>0) {
            if (ghadrmotlagh(x) % tedadmaghsoom(x) == 0) {
            q = zarbargham(x);
        }
            else {q = majmoomaghsoomaval(x);}
        }
         else {if (ghadrmotlagh(x) % tedadmaghsoom(-1 * x) == 0) {
            q = -1 * zarbargham(-1 * x);
        }
            else {q = -1 * majmoomaghsoomaval(-1 * x);}

        }


        printf("%lld%%\n", q+o);
        g = (float)(q+o)/c;
        if (g>k) {
                k=g;
                w=a;
        }

    }
    printf("Best option: %lld", w);

    return 0;
}
