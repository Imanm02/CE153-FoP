#include <stdio.h>
#include <stdlib.h>
char second[33554432];
int main()
{
    int num1, t;
    char first[32] = {0,1,1,1,0,1,1,0,0,1,0,0,1,1,1,1,0,1,1,0,0,1,1,1,0,1,1,0,0,1,1,1};
    char char1[6];
    scanf("%d", &num1);
    for (int i=0; i<num1; i++) {
        t = i%32;
        second[i] = first[t];
    }
    while (1){
        scanf("%s", &char1);
        if ( char1[0] == 'K' ) {return 0;}
        else if ( char1[0] == 'G' ) {get();}
        else if ( char1[0] == 'A' ) {attack();}
    }
    return 0;
}
void get()
{
    int num2, num3;
    scanf("%d%d", &num2, &num3);
    for(int i=num2; i<=num3; i++){
        printf("%d", second[i-1]);
    }
    printf("\n");
}
void attack()
{
    int num4, num5, num6;
    scanf("%d%d%d", &num4, &num5, &num6);
    for(int j=num4; j<=num5; j++){
        second[j-1] = num6;
    }
    printf("\n");
}
