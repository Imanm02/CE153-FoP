#include <stdio.h>
#include <stdlib.h>

int main()
{
    bazgashti(-1);
    return 0;
}
int bazgashti(int cte)
{
    int num1;
    scanf("%d", &num1);
    if (num1 == 0) {
    return 0;
    }

    while (cte <= num1) {
    printf("%d\n", cte);
    num1 = bazgashti(num1);
    if (num1==0){return 0;}
    }

    if (cte > num1) {
    return (num1);
    }

}
