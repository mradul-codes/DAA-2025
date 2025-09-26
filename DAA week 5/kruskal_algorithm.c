# include<stdio.h>
# include<stdlib.h>

typedef struct {
    int src, dest , weight;
} edge;

typedef struct{
    int v,e; // no.of vertex and no. of edge and no.of vertex
    edge*edges;
} graph;

int* parent;

int find(int i){
    if (parent[i] !=i)
    parent[i] = find(parent[i]);
    return parent[i];
}

void unionset(int u, int v) {
    int set_u = find(u);
    int set_v = find(v);
    parent[set_u] = set_v;
}

int compare(const void* a, const void* b) {
    edge* e1 = (edge*)a;
    edge* e2 = (edge*)b;
    return e1->weight - e2->weight;
}

void kruskal(graph* graph)
{
    int V = graph->v;
    edge* result = (edge*)malloc((V - 1) * sizeof(edge));
    int e = 0, i = 0;

    qsort(graph->edges, graph->e, sizeof(edge), compare);

    parent = (int*)malloc(V * sizeof(int));
    for (int v = 0; v < V; ++v)
        parent[v] = v;

    while (e < V - 1 && i < graph->e) {
        edge next = graph->edges[i++];

        int x = find(next.src);
        int y = find(next.dest);

        if (x != y) {
            result[e++] = next;
            unionset(x, y);
        }
    }
        printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);

    free(result);
    free(parent);
}

int main() {
    graph graph;
    graph.v = 4;
    graph.e = 5;

    graph.edges = (edge*)malloc(graph.e * sizeof(edge));

    graph.edges[0] = (edge){0, 1, 10};
    graph.edges[1] = (edge){0, 2, 6};
    graph.edges[2] = (edge){0, 3, 5};
    graph.edges[3] = (edge){1, 3, 15};
    graph.edges[4] = (edge){2, 3, 4};

    kruskal(&graph);

    free(graph.edges);
    return 0;
}