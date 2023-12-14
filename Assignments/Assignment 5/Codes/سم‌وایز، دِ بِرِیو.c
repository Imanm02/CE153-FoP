#include <stdio.h>
#include <stdlib.h>
long long int a = 0;
int main()
{
    int c;
    long long int b;
    scanf("%d", &c);
    for (int i=1; i<=c; i++){
        scanf("%lld", &b);
        bang(b);
        printf("%lld\n", a);
        a = 0;
    }
    return 0;
}
void bang(long long int d)
{
    if (d>0){
        if (d==1) {
            a = a + 1;
        }
        else if (d==2) {
            a = a + 1;
        }
        else if (d==3) {
            a = a + 2;
        }

        else if (d==4) {
            a = a + 3;
        }
        else if (d==5) {
            a = a + 2;
        }
        else if (d==6) {
            a = a + 4;
        }
        else if (d==7) {
            a = a + 3;
        }
        else if (d==8) {
            a = a + 5;
        }
        else if (d==9) {
            a = a + 4;
        }
        else if (d%4==0){
            a = a + 1;
            bang(d-2);
        }
        else if (d%2==0){
            a = a + d/2;
            bang((d/2)-1);
        }
        else if (d%4==1) {
            a = a + 1;
            bang(d-2);
        }
        else if (d%4==3) {
            a = a + 1;
            bang((d-1)/2);
        }
    }
}
