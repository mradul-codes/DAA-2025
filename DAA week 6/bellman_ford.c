#include <stdio.h>
#define inf 99999

struct edge {
    int from, to, weight;
};

void bf(struct edge edges[], int v, int e, int source) {
    int dist[v];
    int parent[v];

    for (int i = 0; i < v; i++) {
        dist[i] = inf;
        parent[i] = -1;
    }
    dist[source] = 0;

    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j].from;
            int to = edges[j].to;
            int w = edges[j].weight;

            if (dist[u] != inf && dist[u] + w < dist[to]) {
                dist[to] = dist[u] + w;
                parent[to] = u;
            }
        }
    }

    for (int j = 0; j < e; j++) {
        int u = edges[j].from;
        int to = edges[j].to;
        int w = edges[j].weight;

        if (dist[u] != inf && dist[u] + w < dist[to]) {
            printf("Negative cycle mil gaya!\n");
            return;
        }
    }

    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < v; i++) {
        printf("%d\t%d\t\t", i, dist[i]);

        int path[100], count = 0;
        int current = i;
        while (current != -1) {
            path[count++] = current;
            current = parent[current];
        }

        for (int j = count - 1; j >= 0; j--) {
            printf("%d", path[j]);
            if (j != 0) printf(" -> ");
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    int E = 5;

    struct edge edges[] = {
        {0, 1, 5},
        {1, 2, 1},
        {1, 3, 2},
        {2, 4, 1},
        {4, 3, -1}
    };

    bf(edges, V, E, 0);
    return 0;
}