#include <stdio.h>

   int main(){
    int a, b, c;
    scanf("%d", &a);
    for(int i=0; i<a; i++){
    int d=0; /* دی ماکس تلپورته*/ /* ابتدای حلقه باید 0 شه هر بار*/
    scanf("%d %d", &b, &c);
    for(int k=1;k<b+1;k++){
    int e, f; /* fflush stint*/
    scanf("%d %d", &e, &f);
    if(e>d) continue;
    if(f>d) d=f;}
    if(d>c-1){printf("YES\n");}
    else{printf("NO\n");}}
    return 0;
}
