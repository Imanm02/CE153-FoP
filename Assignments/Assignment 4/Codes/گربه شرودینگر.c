#include <stdio.h>
#include <stdlib.h>

int recursiveFunction(int cte) {
    int number;
    scanf("%d", &number);
    if (number == 0) return 0;

    while (cte <= number) {
        printf("%d\n", cte);
        number = recursiveFunction(number);
        if (number == 0) return 0;
    }

    return (cte > number) ? number : 0;
}

int main() {
    recursiveFunction(-1);
    return 0;
}