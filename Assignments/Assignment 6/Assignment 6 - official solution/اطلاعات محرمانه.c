#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int n,m,l;

int solve_int(int* ar){
    int mx = 0;
    for(int i=0;i<l;i++){
        for(int j=i+1;j<=l;j++){
            int sum = 0;
            for(int k=i;k<j;k++){
                sum += *(ar+k);
            }
            if(sum > mx)
                mx = sum;
        }
    }
    return mx;
}

char solve_char(char* ar){
    char mx = 0;
    for(int i=0;i<l;i++){
        if(*(ar+i) > mx)
            mx = *(ar+i);
    }
    return tolower(mx);
}

int main(){
    int i,j,k;
    scanf("%d %d %d",&n,&m,&l);
    void*** arr = malloc(n*sizeof(void**));
    int** res = malloc(n * sizeof(int*));
    for(i=0;i<n;i++){
        *(arr+i) = malloc(m*sizeof(void*));
        *(res+i) = malloc(m*sizeof(int));
        for(j=0;j<m;j++){
            char tmp;
            scanf(" %c",&tmp);
            if(tmp=='T'){
                *(*(arr+i) + j) = malloc(sizeof(int)*l + sizeof(char));
                *(char*)(*(*(arr+i) + j) + 0) = 1;
                for(k=0;k<l;k++){
                    scanf("%d",(int*)(*(*(arr+i) + j) + sizeof(char)+k*sizeof(int)));
                }
                (*(*(res+i)+j)) = solve_int(*(*(arr+i) + j) + sizeof(char));
                printf("%d ",(*(*(res+i)+j)));
            }
            else{
                *(*(arr+i) + j) = malloc(sizeof(char)*l + sizeof(char));
                *(char*)(*(*(arr+i) + j) + 0) = 0;
                for(k=0;k<l;k++){
                    scanf(" %c",(char*)(*(*(arr+i) + j) + sizeof(char)+k*sizeof(char)));
                }
                (*(*(res+i)+j)) = solve_char(*(*(arr+i) + j) + sizeof(char));
                printf("%c ",(*(*(res+i)+j)));
            }
        }
        printf("\n");
    }
}