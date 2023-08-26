#include <stdio.h>
#include <stdlib.h>

int a[20][20], visited[20], n;

void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int v;

    printf("\nEnter the number of vertices:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        visited[i] = 0;
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }

    printf("\nEnter graph data in matrix form:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the starting vertex:");
    scanf("%d", &v);

    printf("\nDFS traversal starting from vertex %d:\n", v);
    dfs(v);

    printf("\n");
    return 0;
}

