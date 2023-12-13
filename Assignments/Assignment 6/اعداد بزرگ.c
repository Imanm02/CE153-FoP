#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// armin saghafian
int main()
{
    int mabnayeaddad;
    int max;
    scanf("%d", &mabnayeaddad);
    char *num1 = (char *)calloc(10000, sizeof(char)), *num2 = (char *)calloc(10000, sizeof(char)), *num3 = (char *)calloc(10000, sizeof(char));
    scanf("%s%s", num1, num2);
    int len_num1 = strlen(num1), len_num2 = strlen(num2);
    if (len_num1 > len_num2){
        for (int i = len_num2 - 1; i >= 0; i--){
            *(num2 + i + len_num1 - len_num2) = *(num2 + i);
        }
        for (int i = 0; i < len_num1 - len_num2; i++){
            *(num2 + i) = '0';
        }
    }else if (len_num1 < len_num2){
        for (int i = len_num1 - 1; i >= 0; i--){
            *(num1 + i + len_num2 - len_num1) = *(num1 + i);
        }
        for (int i = 0; i < len_num2 - len_num1; i++){
            *(num1 + i) = '0';
        }
    }
    if (len_num1 > len_num2) {
        max = len_num1;
    }
    else {max = len_num2;}
    for (int i = max - 1; i >= 0; i--){
        if (i == 0){
            if ( *(num1 + i) + *(num2 + i) - 96 >= mabnayeaddad){
                *(num3 + i) = *(num1 + i) + *(num2 + i) - mabnayeaddad - 96;
                printf("1");
            }else {
                *(num3 + i) = *(num1 + i) + *(num2 + i) - 96;
            }
        }else{
            if ( *(num1 + i) + *(num2 + i) - 96 >= mabnayeaddad){
                (*(num1 + i - 1))++;
                *(num3 + i) = *(num1 + i) + *(num2 + i) - mabnayeaddad - 96;
            }else {
                *(num3 + i) = *(num1 + i) + *(num2 + i) - 96;
            }
        }
    }
    for (int i = 0; i < max; i++){
        printf("%d", *(num3 + i));
    }
    return 0;
}
