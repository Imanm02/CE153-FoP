#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[30];
    int b[30];
    int c, d;
    for(int i = 0; i <= 29; i++){
        scanf("%d", &c);
        a[i] = c;
    }
    for(int j = 0; j <= 29; j++){
        scanf("%d", &d);
        b[j] = d;
    }
    for(int k = 0; k <= 29; k++){
        int h = 1;
        for(int o = 0; o <= 29; o++){
        if (a[k]==b[o]){
            h = 0;
        }
    }
    if (h){
        printf("%d\n", a[k]);
    }
    }
    return 0;
}
