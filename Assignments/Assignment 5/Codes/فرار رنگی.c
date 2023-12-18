#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int n, m, colorChangeValue, targetValue;

void dfs(int x, int y);
int isSafe(int x, int y);
void printArray();

int main() {
    int xCor, yCor;
    scanf("%d %d", &m, &n);
    scanf("%d %d", &yCor, &xCor);
    scanf("%d", &colorChangeValue);

    // Initialize map and visited array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            visited[i][j] = map[i][j];
        }
    }

    targetValue = map[yCor - 1][xCor - 1];
    dfs(xCor - 1, yCor - 1);
    printArray();
}

void dfs(int x, int y) {
    visited[y][x] = -1;  // Mark as visited
    int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
    int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

    // Explore all 8 directions
    for (int i = 0; i < 8; i++) {
        if (isSafe(x + dx[i], y + dy[i])) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int isSafe(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && visited[y][x] != -1 && map[y][x] == targetValue;
}

void printArray() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", visited[i][j] != -1 ? visited[i][j] : colorChangeValue);
        }
        printf("\n");
    }
}