#include <stdio.h>
#include <limits.h>
int d[10], p[10], visited[10];
void dijkstra(int a[10][10], int s, int n) {
    int u, v, i, j, min;
    for (v = 0; v < n; v++) {
        d[v] = INT_MAX;
        p[v] = -1;
        visited[v] = 0;
    }
    d[s] = 0;
    for (i = 0; i < n; i++) {
        min = INT_MAX;
        u = -1;
        for (j = 0; j < n; j++) {
            if (visited[j] == 0 && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (v = 0; v < n; v++) {
            if (a[u][v] > 0 && visited[v] == 0 && d[u] != INT_MAX &&
                d[u] + a[u][v] < d[v]) {
                d[v] = d[u] + a[u][v];
                p[v] = u;
            }
        }
    }
}
void path(int v, int s) {
    if (p[v] != -1)
        path(p[v], s);
    if (v != s)
        printf("->%d", v);
}
void display(int s, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i != s) {
            printf("%d", s);
            path(i, s);
            if (d[i] == INT_MAX)
                printf(" = INF\n");
            else
                printf(" = %d\n", d[i]);
        }
    }
}
int main() {
    int a[10][10], i, j, n, s;
    printf("Program for Single Source Shortest Path using Dijkstra's Algorithm\n\n");
    printf("Enter the number of vertices (size of the graph): ");
    scanf("%d", &n);
    printf("Enter the %d x %d cost matrix:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    dijkstra(a, s, n);
    printf("\nOUTPUT\n");
    printf("The shortest paths from %d to remaining vertices are:\n\n", s);
    display(s, n);
    printf("\nThank You\n");
    return 0;
}
