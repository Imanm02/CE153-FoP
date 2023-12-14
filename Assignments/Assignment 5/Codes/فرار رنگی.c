#include <stdio.h>
void printarray();
int safe(int , int);
int map[100][100];
int visited[100][100];
int n, m;
int c;
int val;
void dfs(int x, int y){
    visited[y][x] = -1;
    if(safe(x+1,y)){
        dfs(x+1,y);
    }
    if(safe(x,y+1)){
        dfs(x,y+1);
    }
    if(safe(x-1,y)){
        dfs(x-1,y);
    }
    if(safe(x,y-1)){
        dfs(x,y-1);
    }
    if(safe(x+1,y+1)){
        dfs(x+1,y+1);
    }
    if(safe(x-1,y-1)){
        dfs(x-1,y-1);
    }
    if(safe(x+1,y-1)){
        dfs(x+1,y-1);
    }
    if(safe(x-1,y+1)){
        dfs(x-1,y+1);
    }
}
int safe(int x,int y){
    if(visited[y][x] != -1) {
        if (x < n && x >= 0) {
            if (y < m && y >= 0) {
                if (map[y][x] == val) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
void printarray(){

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] != -1){
            printf("%d ",visited[i][j]);
            }
            else{
                printf("%d ",c);
            }
        }
        printf("\n");
    }
}
int main() {
    //
    int xcor, ycor;
    scanf("%d",&m);
    scanf("%d",&n);
    scanf("%d %d",&ycor,&xcor);
    scanf("%d",&c);
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = map[i][j];
        }
    }
    val = map[ycor-1][xcor-1];
    dfs(xcor-1,ycor-1);
    printarray();
}