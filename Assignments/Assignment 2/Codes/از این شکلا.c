#include <stdio.h>
#include <stdlib.h>

int main()
{
     int n;
     scanf("%d",&n);
     int i,j,m;
for(i=0;i<2*n;i++){
    if (i == n - 1){
        for(j=0;j<n+1;j++){
            printf("* ");
        }
        printf("\n");
    }
    if (i == 2 * n - 1){
        for(j=0;j<n;j++){
            printf("* ");
        }
        for(j=0;j<n-1;j++){
            printf("  ");
        }
        printf("*");
    }
    else if (i == 0){
        printf("* ");
        for(j=0;j<n - i - 1;j++){
            printf("  ");
        }
        for(j=0;j<n;j++){
            printf("* ");
        }
        printf("\n");
    }
    else if (i == n){
        for(j=0;j<n - 1;j++){
            printf("  ");
        }
        for(j=0;j<n + 1;j++){
            printf("* ");
        }
        printf("\n");
    }
    else if (i < n - 1){
        printf("* ");
        for(j=0; j<i - 1;j++){
            printf("  ");
        }
        printf("* ");
        for(j=0;j<n - i - 1;j++){
            printf("  ");
        }
        printf("* ");
        for(j=0;j<n - i - 2;j++){
            printf("  ");
        }
        printf("*\n");
    }
    else if(i > n){
        m = i - n;
        for(j=0;j<n - m - 1;j++){
            printf("  ");
        }
        printf("* ");
        for(j=0;j<m - 1;j++){
            printf("  ");
        }
        printf("* ");
        for(j=0;j<m;j++){
            printf("  ");
        }
        printf("* ");
        for(j=0;j<n - m - 2;j++){
            printf("  ");
        }
        printf("*\n");
    }
}
    return 0;
}
