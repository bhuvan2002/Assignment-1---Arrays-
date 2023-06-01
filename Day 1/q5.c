#include <stdio.h>
#include <stdlib.h>

void mergeArrays(int* arr1, int* arr2, int n1, int n2, int* arr3) {
    int i = 0, j = 0, k = 0;
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
    for (i = 0; i < n1 + n2 - 1; i++) {
        for (j = 0; j < n1 + n2 - i - 1; j++) {
            if (arr3[j] > arr3[j + 1]) {
                int temp = arr3[j];
                arr3[j] = arr3[j + 1];
                arr3[j + 1] = temp;
            }
        }
    }
}
int main() {
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int* arr3 = (int*)malloc((n1 + n2) * sizeof(int));

    mergeArrays(arr1, arr2, n1, n2, arr3);

    printf("Array after merging: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    free(arr3);
    return 0;
}
