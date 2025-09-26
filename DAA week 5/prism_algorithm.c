#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define v 5  // number of vertices

int min(int key[], bool mst[]) {
    int min_val = INT_MAX, idx;

    for (int i = 0; i < v; i++)
        if (!mst[i] && key[i] < min_val)
            min_val = key[i], idx = i;

    return idx;
}

void print(int parent[], int g[v][v]) {
    printf("edge\tweight\n");
    for (int i = 1; i < v; i++)
        printf("%d - %d\t%d\n", parent[i], i, g[i][parent[i]]);
}

void prim(int g[v][v]) {
    int parent[v];
    int key[v];
    bool mst[v];

    for (int i = 0; i < v; i++)
        key[i] = INT_MAX, mst[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < v - 1; i++) {
        int u = min(key, mst);
        mst[u] = true;

        for (int j = 0; j < v; j++)
            if (g[u][j] && !mst[j] && g[u][j] < key[j])
                parent[j] = u, key[j] = g[u][j];
    }

    print(parent, g);
}

int main() {
    int g[v][v] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    prim(g);

    return 0;
}