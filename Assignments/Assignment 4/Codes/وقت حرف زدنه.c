#include <stdio.h>
#include <stdlib.h>
int a=1, b=0;
int main()
{
   geta();
   if (b>=a) {printf("%d. YES", 2*a);}
   else {printf("%d. NO", a+b+1);}
}
void geta()
{
    char talk;
    scanf("%c", &talk);
    if (talk == 'a'){
        a++;
        geta();}
    else if (talk == 'b'){
        b++;
        getb();}
}
void getb()
{
    char talk;
    scanf("%c", &talk);
    if (talk == 'b'){
        b++;
        getb();}
}
