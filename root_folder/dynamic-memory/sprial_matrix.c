#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int size;
    printf("Enter the size of the matrix: ");
    scanf("%d", &size);

    bool **visited = (bool**)malloc(size * sizeof(bool*));
    for (int i = 0; i < size; i++) {
        visited[i] = (bool*)malloc(size * sizeof(bool));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            visited[i][j] = false;
        }
    }


    int **spiral_matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        spiral_matrix[i] = (int*)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            spiral_matrix[i][j] = -1;
        }
    }

    int directions[4][2] = {
        {0, 1},  // Move right
        {1, 0},  // Move down
        {0, -1}, // Move left
        {-1, 0}  // Move up
    };

    int cur_dir = 0;
    int row = 0, col = 0;
    spiral_matrix[row][col] = 1;
    visited[row][col] = true;

    int count = 1;
    int total_elements = size * size;


    while (count < total_elements) {
        int next_row = row + directions[cur_dir][0];
        int next_col = col + directions[cur_dir][1];

        if (next_row < 0 
                || next_row >= size 
                || next_col < 0 
                || next_col >= size 
                || visited[next_row][next_col]
        ) {
            cur_dir = (cur_dir + 1) % 4;
            next_row = row + directions[cur_dir][0];
            next_col = col + directions[cur_dir][1];
        }

        row = next_row;
        col = next_col;
        spiral_matrix[row][col] = ++count;
        visited[row][col] = true;
    }

    printf("Spiral Matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", spiral_matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++) {
        free(visited[i]);
        free(spiral_matrix[i]);
    }
    free(visited);
    free(spiral_matrix);

    return 0;
}