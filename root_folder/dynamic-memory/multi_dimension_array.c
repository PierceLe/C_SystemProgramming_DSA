#include <stdio.h>
#include <stdlib.h>

int main() {
    int size_a, size_b;
    printf("Enter size of array: ");
    scanf("%d", &size_a);
    scanf("%d", &size_b);
    int *arr1;
    int *arr2;
    arr1 = (int*)malloc(size_a * sizeof(int));
    for (int i = 0; i < size_a; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }
    arr2 = (int*)malloc(size_b * sizeof(int));
    for (int i = 0; i < size_b; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    int **arr3;
    arr3 = (int**)malloc(size_a * sizeof(int*));
    for (int i = 0; i < size_a; i++) {
        arr3[i] = (int*)malloc(size_b * sizeof(int));
    }

    for (int i = 0; i < size_a; i++) {
        for (int j = 0; j < size_b; j++) {
            arr3[i][j] = arr1[i] * arr2[j];
        }
    }

    for (int i = 0; i < size_a; i++) {
        for (int j = 0; j < size_b; j++) {
            printf("%d | ", arr3[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < size_a; i++) {
        free(arr3[i]);
    }
    free(arr3);
    return 0;
}