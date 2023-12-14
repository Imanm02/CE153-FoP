#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, a;
    scanf("%d", &i);
    int bang[i][i];
    for (int x = 0; x < i; x++){
        for (int y = 0; y < i; y++){
            scanf("%d", &a);
            bang[x][y] = a ;
        }
    }
    for (int z = 0; z <= (2 * i) - 2; z++){
        if (z%2 == 0){
            for (int x = i - 1; x > -1; x--){
                for (int y = 0; y <= i - 1; y++){
                    if (x+y == z) {printf("%d ", bang[x][y]);}
                }
            }
        }
        else if (z%2 == 1){
            for (int x = 0; x <= i - 1; x++){
                for (int y = i - 1; y > -1; y--){
                    if (x+y == z) {printf("%d ", bang[x][y]);}
                }
            }
        }}
    return 0;
}
