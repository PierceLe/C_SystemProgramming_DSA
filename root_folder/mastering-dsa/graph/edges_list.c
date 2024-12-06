#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n_vertex, n_edge;
    scanf("%d %d", &n_vertex, &n_edge);

    // Khởi tạo danh sách kề
    int*** edges_list = malloc((n_vertex + 1) * sizeof(int**));
    for (int i = 0; i <= n_vertex; i++)
    {
        edges_list[i] = NULL; // Ban đầu NULL
    }

    for (int i = 0; i < n_edge; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        // Tính kích thước mới (mở rộng thêm 1 con trỏ)
        size_t old_size = edges_list[u] ? sizeof(edges_list[u]) : 0;
        size_t new_size = old_size + sizeof(int*);

        // Mở rộng vùng nhớ
        edges_list[u] = realloc(edges_list[u], new_size);

        // Gán con trỏ mới vào vùng nhớ vừa mở rộng
        edges_list[u][old_size / sizeof(int*)] = malloc(2 * sizeof(int));
        edges_list[u][old_size / sizeof(int*)][0] = v;
        edges_list[u][old_size / sizeof(int*)][1] = w;
    }

    // In danh sách kề
    for (int i = 0; i <= n_vertex; i++)
    {
        printf("Vertex %d:", i);
        if (edges_list[i] != NULL)
        {
            for (int j = 0; j < sizeof(edges_list[i]) / sizeof(int*); j++)
            {
                printf(" (%d %d)", edges_list[i][j][0], edges_list[i][j][1]);
            }
        }
        printf("\n");
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i <= n_vertex; i++)
    {
        if (edges_list[i] != NULL)
        {
            for (int j = 0; j < sizeof(edges_list[i]) / sizeof(int*); j++)
            {
                free(edges_list[i][j]);
            }
            free(edges_list[i]);
        }
    }
    free(edges_list);

    return 0;
}