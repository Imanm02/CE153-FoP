#include "grader.h"
#include <stdio.h>
#include <stdarg.h>

#define calc(a, b, c) ((a) c (b))

long long int maximum(long long int a, long long int b, long long int c)
{
    if (a >= b && a >= c) {return a;}
    else if (b >= a && b >= c) {return b;}
    else {return c;}
}
long long int minimum(long long int a, long long int b, long long int c)
{
    if (a <= b && a <= c) {return a;}
    else if (b <= a && b <= c) {return b;}
    else {return c;}
}
long long int majmomagh(long long int n) {
    long long int p=0;
    if (n==0) {return 0;}
    else if (n==1) {return 1;}
    for (long long int i=1; i<=n; i++){
        if (n%i==0) {
                p += i;
        }
    }
    return p;
}
long long int majmomaghh(long long int n) {
    long long int p=0;
    if (n==0) {return 0;}
    else if (n==1) {return 1;}
    for (long long int i=1; i*i<=n; i++){
        if (n%i==0) {
                p += i;
                p += n/i;
        }
    }
    return p;
}

#if s == 0
long long int findDivisorSum(char d, int a, int b, int c){
        if(d == 'M'){
            return maximum(majmomaghh(a), majmomaghh(b), majmomaghh(c));
        }
        else if(d == 'm'){
            return minimum(majmomaghh(a), majmomaghh(b), majmomaghh(c));
        }
}

#else
long long int findDivisorSum(int a, ...){
        va_list arg;
        long long int javabema;
        va_start (arg, a);
        javabema = majmomagh(va_arg(arg, long long int));
        for(int i = 1; i < a ; i++){
            long long int b = majmomagh(va_arg(arg, long long int));
            if (javabema>b) {javabema = b;}}
        va_end(arg);
        return javabema;
}

#endif

long long run(char type, int num1, int num2, int num3, int num4) {
    return findDivisorSum(type,
    calc(num1, num2, +),
    calc(num1, num2, -),
    calc(num3, num4, *));
}