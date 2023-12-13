#include <stdio.h>
#include <stdlib.h>
// armin saghafian
int main()
{
    long long int *arr1 = (long long int *)calloc(10010, sizeof(long long));
    long long int *arr2 = (long long int *)calloc(10010, sizeof(long long));
    long long int num1, num2, count = 0;
    while(!0){
        scanf("%lld", &num1);
        if (num1 == -1){
            break;
        }else {
            scanf("%lld", &num2);
        }
        *(arr1 + count) = num1;
        *(arr2 + count) = num2;
        count++;
    }
    int temp = 1;
    for (int i = 0; i <= count; i++){
        for (int j = i + 1; j <= count; j++){
            if (*(arr2 + i) == *(arr2 + j)) {
                *(arr2 + j) = 0;
                temp = 0;
            }
        }
        if (temp == 0) {
            *(arr2 + i) = 0;
            temp = 1;
        }
    }
    long long int min = -10;
    for (int i = 0; i <= count; i++) {
        if (*(arr2 + i) > 0 || *(arr2 + i) < 0) {
            min = *(arr2 + i);
            break;
        }
    }
    if (min == -10){
        printf("no one won.");
        return 0;
    }
    int temp3;
    for (int i = 0; i <= count; i++){
        if ( *(arr2 + i) < min && *(arr2 + i) != 0){
            min = *(arr2 + i);
            temp3 = i;
        }
    }
    int temp2 = 0;
    for (int i = 0; i <= count; i++){
        if (*(arr1 + temp3) == *(arr1 + i)){
            temp2++;
        }
    }

    if ( temp2 != 1 ){
        printf("%d cheated.", *(arr1 + temp3));
    }else{
        printf("%d won.", *(arr1 + temp3));
    }
    return 0;
}
