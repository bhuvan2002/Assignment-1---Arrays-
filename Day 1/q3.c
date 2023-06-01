#include <stdio.h>

int searchInsert(int* arr, int arrSize, int target) {
    int low = 0;
    int high = arrSize - 1;
    int ans = arrSize; 
    while (low <= high) {
        int mid = (high + low) / 2;

        if (target == arr[mid]) {
            return mid;
        } else if (target > arr[mid]) {
            low = mid + 1;
        } else {
            ans = mid; 
            high = mid - 1;
        }
    }
    return ans;
}
int main() {
    int arr[] = {1, 3, 5, 6};
    int target = 5;
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int result = searchInsert(arr, arrSize, target);
    printf("%d\n", result);
    return 0;
}
