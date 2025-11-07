#include<stdio.h>
#define inf 99999
#define v 4

void fw(int graph[v][v]) {
    int dist[v][v];
    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for(int k=0;k<v;k++) {
        for(int i=0;i<v;i++) {
            for(int j=0;j<v;j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i=0;i<v;i++) {
        for(int j=0;j<v;j++) {
            if(dist[i][j] == inf)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[v][v] = {
        {0, 5, inf, 10},
        {inf, 0, 3, inf},
        {inf, inf, 0, 1},
        {inf, inf, inf, 0}
    };
    fw(graph);
    return 0;
}