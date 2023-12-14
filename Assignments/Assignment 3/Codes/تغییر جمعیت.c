#include <stdio.h>
#include <stdlib.h>

int main(){
    int x,y,t;
    scanf("%d" ,&t);
    while(t--){
        scanf("%d%d" ,&x,&y);
        if (check(x,y))
            printf("YES\n");
        else
            printf("NO\n");
}
    return 0;
}
int check (x,y) {
    int a=1;
    if (x==1 && y!=1) {
        a=0;
    }
    else if (x==2 && y>3) {
        a=0;
    }
    else if (x==3 && y>3) {
        a=0;
    }
    else if (x==0) {
        a=0;
    }
    else {
        a=1;
}
    return a;
}

