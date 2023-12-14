#include <stdio.h>

int main () {
   int a;
   scanf("%d",&a);
   int i = 0;
   for(;i<2*a - 1;i++){
    if (i < a) {
        int j = 0;
        for(;j<i+1;j++){
            printf("*");
        }
        for(j=0;j<2*a-2*i-2;j++){
            printf(" ");
        }
        for(j=0;j<i+1;j++){
            printf("*");
        }
        printf("\n");
    } else {
        int j = 0;
        for(;j<a - i%a - 1;j++){
            printf("*");
        }
        for(j=0;j<2*a-2*(a - i%a - 2)-2;j++){
            printf(" ");
        }
        for(j=0;j<a - i%a - 1;j++){
            printf("*");
        }
        printf("\n");
    }
   }
   return 0;
}
