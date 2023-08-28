#include <stdio.h>
#include <stdbool.h>

#define INFINITY 9999
#define MAX 10

void dijkstra(int G[MAX][MAX], int n, int startnode);

int main() {
    int G[MAX][MAX], i, j, n, u;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);
    printf("Enter the starting node: ");
    scanf("%d", &u);
    dijkstra(G, n, u);
    return 0;
}

void dijkstra(int G[MAX][MAX], int n, int startnode) {
    int distance[MAX], pred[MAX];
    bool visited[MAX] = { false };
    int i, j, count, mindistance, nextnode;
    
    // Initialize distance and pred arrays
    for (i = 0; i < n; i++) {
        distance[i] = G[startnode][i];
        pred[i] = startnode;
    }

    distance[startnode] = 0;
    visited[startnode] = true;
    count = 1;

    while (count < n) {
        mindistance = INFINITY;
        for (i = 0; i < n; i++) {
            if (distance[i] < mindistance && !visited[i]) {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = true;

        for (i = 0; i < n; i++) {
            if (!visited[i] && mindistance + G[nextnode][i] < distance[i]) {
                distance[i] = mindistance + G[nextnode][i];
                pred[i] = nextnode;
            }
        }
        count++;
    }

    // Print the shortest paths
    for (i = 0; i < n; i++) {
        if (i != startnode) {
            printf("Distance of %d = %d\n", i, distance[i]);
            printf("Path = %d", i);
            j = i;
            do {
                j = pred[j];
                printf(" <- %d", j);
            } while (j != startnode);
            printf("\n");
        }
    }
}
