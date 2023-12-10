#include <stdio.h>
#include <stdlib.h>

int main(){

    int n, m;
    scanf("%d\n", &n);
    scanf("%d", &m);
    int c2 = 0, c4 = 0;
    int z;
    int o =1;
    for(int y = 0; y <n ; y++)
        {char c1;
        scanf(" %c", &c1); /*  c1 = getchar(); */
        switch (c1){ /*            تبدیل یه یه عدد چند رقمی   */
            case 'a' : c2 = c2*10 + 1;
        break;
            case 'b' : c2 = c2*10 + 2;
        break;
            case 'c' : c2 = c2*10 + 3;
        break;
            case 'd' : c2 = c2*10 + 4;
        break;
            case 'e' : c2 = c2*10 + 5;
        break;
            case 'f' : c2 = c2*10 + 6;
        break;
            case 'g' : c2 = c2*10 + 7;
        break;
            case 'h' : c2 = c2*10 + 8;
        break;
            case 'i' : c2 = c2*10 + 9;
        break;
        }/*     just like last one     */
    }
    for (int x = 0; x <m ; x++){
        char c3;
        scanf(" %c", &c3);
        switch (c3){
            case 'a' : c4 = c4*10 + 1;
        break;
            case 'b' : c4 = c4*10 + 2;
        break;
            case 'c' : c4 = c4*10 + 3;
        break;
            case 'd' : c4 = c4*10 + 4;
        break;
            case 'e' : c4 = c4*10 + 5;
        break;
            case 'f' : c4 = c4*10 + 6;
        break;
            case 'g' : c4 = c4*10 + 7;
        break;
            case 'h' : c4 = c4*10 + 8;
        break;
            case 'i' : c4 = c4*10 + 9;
        break;}}
     /*     مقایسه              */
    for (int z = 0; z < m ; z++){ o = o * 10; }
    int c5=0;
    for (int i = 0 ; i < n - m + 1 ; i++){
        if (c2 % o == c4){ break; }
    else {c5 = c5 + 1 ; c2 = c2 / 10;}}
    int c6 = n - m - c5 ;/* After 100 times testing :)*/
    if (c6 > 0){ printf("%d", c6);}
        else if (c6 == 0){ printf("%d", c6); }
        else{ printf("-1"); }

    return 0; // لطفا طراح این سوال رو معرفی کنید
}
