#include <stdio.h>
#include <stdlib.h>
void Shekl(int n)
{
    for(int i=1; i<=2*n; i++){
        for(int j=1; j<=2*n; j++){
            if (i==1 || j==2*n - i + 1){
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
void tekrar(int n)
{
    if (n > 0){
        Shekl(n);
        tekrar(n-1);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    tekrar(n);
    return 0;
}
