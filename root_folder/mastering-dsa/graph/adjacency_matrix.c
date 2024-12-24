#include <stdio.h>
#include <stdlib.h>
// n_vertex starting from 0
int main()
{
    int n_vertex, n_edge;
    printf("Enter number of vertices and edges: \n");
    scanf("%d %d", &n_vertex, &n_edge);
    int** adjacency_matrix = (int**)malloc(n_vertex * sizeof(int*));
    for (int i = 0; i < n_vertex; i++)
    {
        adjacency_matrix[i] = (int*)malloc(n_edge * sizeof(int));
    }

    // init all values in the matrix is -1 first
    for (int i = 0; i < n_vertex; i++)
    {
        for (int j = 0; j < n_edge; j++)
        {
            adjacency_matrix[i][j] = -1;
        }
    }

    // handle input edge and weight
    for (int i = 0; i < n_edge; i++)
    {
        int u, v, w;
        printf("Enter edge and their weighted \n");
        scanf("%d %d %d", &u, &v, &w);
        adjacency_matrix[u][v] = w;
        adjacency_matrix[v][u] = w;

    }
    printf("Adjacency matrix:\n");
    // for printing the matrix
    for (int i = 0; i < n_vertex; i++) {
        for (int j = 0; j < n_vertex; j++) {
            printf("%d | ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }

    // free memory space
    for (int i = 0; i < n_vertex; i++)
    {
        free(adjacency_matrix[i]);
    }
    free(adjacency_matrix);
}
