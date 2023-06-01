#include <stdio.h>
#include <math.h>

int smallestRangeI(int* nums, int numsSize, int k) {
    int max = INT_MIN;
    int min = INT_MAX;

    // Find the maximum and minimum values in the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
        if (nums[i] < min) {
            min = nums[i];
        }
    }

    int range = max - min - 2 * k;

    if (range < 0) {
        return 0;
    }

    return range;
}

int main() {
    int nums[] = {1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 0;

    int result = smallestRangeI(nums, numsSize, k);
    printf("The smallest range is %d\n", result);

    return 0;
}
