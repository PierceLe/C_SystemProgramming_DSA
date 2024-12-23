#include <stdio.h>
#include <stdlib.h>

int main()
{
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
    arr1 = (int*)realloc(arr1, (size_a + size_b)* sizeof(int));
    for (int i = size_a; i < size_a + size_b; i++) {
        arr1[i] = arr2[i - size_a];
    }
    free(arr1);
    free(arr2);
}