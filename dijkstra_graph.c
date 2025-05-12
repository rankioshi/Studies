#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 7  // 7 vertices

typedef struct Node {
    int v, weight;
    struct Node* next;
} Node;

Node* graph[V];

void addEdge(int u, int v, int weight) {
    Node* newNode = malloc(sizeof(Node));
    newNode->v = v;
    newNode->weight = weight;
    newNode->next = graph[u];
    graph[u] = newNode;
}

void dijkstra(int src) {
    int dist[V]; bool vis[V] = {0};
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        int u = -1;
        for (int j = 0; j < V; j++)
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) u = j;

        if (u == -1) break; // No accessible vertex left
        vis[u] = 1;

        for (Node* a = graph[u]; a; a = a->next)
            if (dist[u] + a->weight < dist[a->v])
                dist[a->v] = dist[u] + a->weight;
    }

    for (int i = 0; i < V; i++)
        printf("dist[%d] = %d
", i, dist[i]);
}

int main() {
    // Bidirectional edges as in the graph image
    addEdge(0, 1, 1); addEdge(1, 0, 1);
    addEdge(0, 2, 3); addEdge(2, 0, 3);
    addEdge(0, 3, 6); addEdge(3, 0, 6);

    addEdge(1, 3, 4); addEdge(3, 1, 4);
    addEdge(1, 5, 9); addEdge(5, 1, 9);

    addEdge(2, 5, 2); addEdge(5, 2, 2);

    addEdge(3, 4, 3); addEdge(4, 3, 3);
    addEdge(3, 5, 2); addEdge(5, 3, 2);

    addEdge(4, 5, 4); addEdge(5, 4, 4);
    addEdge(5, 6, 11); addEdge(6, 5, 11);

    dijkstra(0);
    return 0;
}
