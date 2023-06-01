#include <stdio.h>

int getPairsCount(int arr[], int n, int sum) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int arr[] = {1, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 4;

    int pairCount = getPairsCount(arr, n, sum);
    printf("Count of pairs is %d\n", pairCount);

    return 0;
}
