#include <stdio.h>
#include <stdlib.h>

int main() {
    int n_vertex, n_edge;
    printf("Enter number of vertices and edges: \n");
    scanf("%d %d", &n_vertex, &n_edge);

    int*** edges_list = (int***)malloc(n_vertex * sizeof(int**));
    for (int i = 0; i < n_vertex; i++) {
        edges_list[i] = (int**)malloc(sizeof(int*));
    }
    for (int i = 0; i < n_edge; i++) {
        printf("Please enter vertices u, v and its weight: ");
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges_list[u][sizeof(edges_list[u]) / sizeof(int*) - 1] = (int*)malloc(2 * sizeof(int));
        edges_list[u][sizeof(edges_list[u]) / sizeof(int*) - 1][0] = v;
        edges_list[u][sizeof(edges_list[u]) / sizeof(int*) - 1][1] = w;
        edges_list[u] = (int**)realloc(edges_list[u],sizeof(edges_list[u]) + sizeof(int*));

        edges_list[v][sizeof(edges_list[v]) / sizeof(int*) - 1] = (int*)malloc(2 * sizeof(int));
        edges_list[v][sizeof(edges_list[v]) / sizeof(int*) - 1][0] = u;
        edges_list[v][sizeof(edges_list[v]) / sizeof(int*) - 1][1] = w;
        edges_list[v] = (int**)realloc(edges_list[v],sizeof(edges_list[u]) + sizeof(int*));
    }

    for (int i = 0; i < n_vertex; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < sizeof(edges_list[i]) / sizeof(int*); j++) {
            printf("[ %d, %d ] ,", edges_list[i][j][0], edges_list[i][j][1]);
        }
        printf("\n");
    }

    for (int i = 0; i < n_vertex; i++) {
        for (int j = 0; j < sizeof(edges_list[i]) / sizeof(int*); j++) {
            free(edges_list[i][j]);
        }
        free(edges_list[i]);
    }
    free(edges_list);
    return 0;
}