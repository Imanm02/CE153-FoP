#include <stdio.h>

int main () {
    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    c = abs(a-b);
    if (aval (c)) {printf("YES");}
    else {printf ("NO");}
    return 0;
}

int aval(int n){
    int i;
    if (n == 2) return 1;
    if (n == 0 || n == 1) return 0;
    for(i=2;i<pow(n,0.5)+1;i++){
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
}
