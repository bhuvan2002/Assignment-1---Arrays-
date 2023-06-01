#include <stdio.h>
#include <stdbool.h>

bool isMonotonic(int* nums, int numsSize) {
    int diff = 0;
    for (int i = 0; i < numsSize - 1; ++i) {
        if (nums[i] != nums[i + 1] && diff == 0)
            diff = nums[i] - nums[i + 1];
        else if ((nums[i] > nums[i + 1] && diff < 0) ||
                 (nums[i] < nums[i + 1] && diff > 0))
            return false;
    }
    return true;
}

int main() {
    int nums[] = {1, 2, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    bool isMonotonicResult = isMonotonic(nums, numsSize);
    printf("The given array is %s\n", isMonotonicResult ? "monotonic" : "not monotonic");

    return 0;
}
