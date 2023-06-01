#include <stdio.h>
#include <stdbool.h>

bool containsDuplicate(int* nums, int numsSize) {
    int i;
    int* seen = (int*)calloc(numsSize, sizeof(int));

    for (i = 0; i < numsSize; i++) {
        if (seen[nums[i]] == 1) {
            free(seen);
            return true;
        }
        seen[nums[i]] = 1;
    }

    free(seen);
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    bool result = containsDuplicate(nums, numsSize);
    printf("%s\n", result ? "true" : "false");

    return 0;
}
