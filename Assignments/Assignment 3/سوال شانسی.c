#include <stdio.h>
#include <stdlib.h>

int shans(int m){
    int k = m;
    int a = 1;
    while (k > 0){
        if (k % 10 != 4 && k % 10 != 7) {
            a = 0;
        }
        k /= 10;
    }
    return a;
}

int tshans(int m){
    int i;
    for(i = 4;i<=m;i++){
        if (m % i == 0){
            if (shans(i)){
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int n,i,m;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&m);
        if(tshans(m)){
                printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
